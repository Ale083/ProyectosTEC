#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btnPausa->setEnabled(false);
    ui->btnResumir->setEnabled(false);
    ui->btnDetener->setEnabled(false);
    energiaCola = new cola<QString>();
    energiaThread = new EnergiaThread("Energia Thread 1",energiaCola,ui->lblColaEnergia,ui->lblCountdownEnergia,ui->sbxEnergia,ui->sbxCapacidadColaEnergia,ui->checkBoxEnergia,&mutexColaEnergia);


    materialCola = new cola<QString>();
    materialThread = new MaterialThread("Material Thread 1",materialCola,ui->lblColaMaterial,ui->lblCountdownMaterial,ui->sbxMaterial,ui->sbxCapacidadColaMaterial,ui->checkBoxMaterial,&mutexColaMaterial);


    maldadCola = new cola<QString>();
    maldadThread = new MaldadThread("Maldad Thread 1", maldadCola, ui->lblColaMaldad, ui->lblCountdownMaldad, ui->sbxMaldad, ui->sbxCapacidadColaMaldad, ui->checkBoxMaldad,&mutexColaMaldad);


    colaDeMonstruos = new cola<Monstruo*>;
    basureroDeMonstruos = new Lista<Monstruo*>;
    combinarThread = new CombinarThread("Combinar Thread 1",energiaCola, materialCola, maldadCola, ui->lblCountdownCombinar,ui->sbxCombinar,ui->checkBoxCombinar,ui->lblColaMonstruos,ui->sbxCapacidadColaDeMonstruos,colaDeMonstruos,basureroDeMonstruos,&mutexColaEnergia,&mutexColaMaterial,&mutexColaMaldad, &mutexColaMonstruos);

    colaBandeja1 = new cola<Monstruo*>;
    colaBandeja2 = new cola<Monstruo*>;
    colaBandeja3 = new cola<Monstruo*>;
    colaBandeja4 = new cola<Monstruo*>;
    colaRobot1 = new cola<Monstruo*>;
    colaRobot2 = new cola<Monstruo*>;
    hornoThread = new HornoThread("Horno Thread 1", colaDeMonstruos, colaBandeja1, ui->checkBoxBandeja1, ui->lblContenido1, ui->sbxBandeja1, colaBandeja2, ui->checkBoxBandeja2, ui->lblContenido2, ui->sbxBandeja2, colaBandeja3, ui->checkBoxBandeja3, ui->lblContenido3, ui->sbxBandeja3, colaBandeja4, ui->checkBoxBandeja4, ui->lblContenido4, ui->sbxBandeja4, ui->lblCountdownHorno, ui->sbxHorno, &mutexColaMonstruos,colaRobot1, ui->sbxCapacidadColaRobot1, &mutexColaRobot1);

    listaDePedidos = new Lista<Pedido*>;
    listaDePedidosPrioridad = new Lista<Pedido*>;

    almacen = new Almacen(listaDePedidos,listaDePedidosPrioridad);

    robot1Thread = new Robot1Thread("Robot 1 Thread", colaRobot1, ui->checkBoxRobot1, ui->sbxProbaRobot1, colaRobot2, basureroDeMonstruos, ui->sbxCapacidadColaRobot1, ui->sbxCapacidadColaRobot2, &mutexColaRobot1, &mutexColaRobot2);

    robot2Thread = new Robot2Thread("Robot 2 Thread", colaRobot2, ui->checkBoxRobot2, ui->sbxProbaRobot2, almacen, basureroDeMonstruos, ui->sbxCapacidadColaRobot2, &mutexColaRobot2, &mutexListaAlmacen);


    refresh = new Refresh(energiaCola,materialCola,maldadCola,ui->lblColaEnergia,ui->sbxCapacidadColaEnergia,ui->lblColaMaterial, ui->sbxCapacidadColaMaterial, ui->lblColaMaldad, ui->sbxCapacidadColaMaldad, colaDeMonstruos, ui->lblColaMonstruos,ui->sbxCapacidadColaDeMonstruos, colaBandeja1, ui->lblContenido1, colaBandeja2, ui->lblContenido2, colaBandeja3, ui->lblContenido3, colaBandeja4, ui->lblContenido4, colaRobot1, ui->lblColaRobot1, ui->sbxCapacidadColaRobot1, colaRobot2, ui->lblColaRobot2, ui->sbxCapacidadColaRobot2, listaAlmacen, ui->lblAlmacenCant, basureroDeMonstruos, ui->lblBasureroCant, &mutexColaEnergia,&mutexColaMaterial,&mutexColaMaldad);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRefresh_clicked(){

    QDir dirPedidos("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\pedidos"); //carpeta de pedidos
    QFileInfoList listaArchivos = dirPedidos.entryInfoList(QDir::Files);
    qDebug() << "Ruta de pedidos:" << dirPedidos.absolutePath();
    QString nombreArchivoEspecifico = "pedido_especifico.txt";
    QString rutaArchivo = dirPedidos.absoluteFilePath(nombreArchivoEspecifico);
    qDebug() << rutaArchivo;
    QFile archivo("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraColaMonstruos.txt");

    if (!listaArchivos.isEmpty()) {
        QFileInfo archivoInfo = listaArchivos.at(0); //el primer archivo de la lista

        // Mantén el archivo en su ubicación original y simplemente escribe en él
        QFile archivo(archivoInfo.absoluteFilePath());
        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {  // Modo Append para no sobrescribir
            QTextStream stream(&archivo);
            stream << "Este archivo ha sido procesado." << Qt::endl;
            archivo.close();
            qDebug() << "Texto escrito en el archivo procesado:" << archivoInfo.fileName();
        } else {
            qDebug() << "Error al abrir el archivo para escribir.";
        }
    } else {
        qDebug() << "No hay archivos en la carpeta de pedidos.";
    }


}


void MainWindow::on_btnIniciar_clicked()
{
    energiaThread -> start();
    materialThread -> start();
    maldadThread->start();
    combinarThread -> start();
    hornoThread -> start();
    robot1Thread->start();
    robot2Thread->start();
    refresh -> start();
    ui->btnIniciar->setEnabled(false);
    ui->btnPausa->setEnabled(true);
    ui->btnDetener->setEnabled(true);

}


void MainWindow::on_btnPausa_clicked()
{
    ui->checkBoxBandeja1->isEnabled() ? ui->checkBoxBandeja1->setChecked(false) : ui->checkBoxBandeja1->setChecked(true);
    ui->checkBoxBandeja2->isEnabled() ? ui->checkBoxBandeja2->setChecked(false) : ui->checkBoxBandeja2->setChecked(true);
    ui->checkBoxBandeja3->isEnabled() ? ui->checkBoxBandeja3->setChecked(false) : ui->checkBoxBandeja3->setChecked(true);
    ui->checkBoxBandeja4->isEnabled() ? ui->checkBoxBandeja4->setChecked(false) : ui->checkBoxBandeja4->setChecked(true); //Si está enabled, es decir si aún sigue vacío.
    hornoThread->pause();
    ui->checkBoxRobot1->setChecked(false);
    ui->checkBoxRobot2->setChecked(false);
    ui->checkBoxCombinar->setChecked(false);
    ui->checkBoxEnergia->setChecked(false);
    ui->checkBoxMaterial->setChecked(false);
    ui->checkBoxMaldad->setChecked(false);
    ui->btnPausa->setEnabled(false);
    ui->btnResumir->setEnabled(true);

}


void MainWindow::on_btnResumir_clicked()
{
    ui->checkBoxBandeja1->isEnabled() ? ui->checkBoxBandeja1->setChecked(true) : ui->checkBoxBandeja1->setChecked(false);
    ui->checkBoxBandeja2->isEnabled() ? ui->checkBoxBandeja2->setChecked(true) : ui->checkBoxBandeja2->setChecked(false);
    ui->checkBoxBandeja3->isEnabled() ? ui->checkBoxBandeja3->setChecked(true) : ui->checkBoxBandeja3->setChecked(false);
    ui->checkBoxBandeja4->isEnabled() ? ui->checkBoxBandeja4->setChecked(true) : ui->checkBoxBandeja4->setChecked(false);
    hornoThread->resume();
    ui->checkBoxRobot1->isEnabled() ? ui->checkBoxRobot1->setChecked(true) : ui->checkBoxRobot1->setChecked(false);
    ui->checkBoxRobot2->isEnabled() ? ui->checkBoxRobot2->setChecked(true) : ui->checkBoxRobot2->setChecked(false);
    ui->checkBoxCombinar->isEnabled() ? ui->checkBoxCombinar->setChecked(true) : ui->checkBoxCombinar->setChecked(false);
    ui->checkBoxEnergia->isEnabled() ? ui->checkBoxEnergia->setChecked(true) : ui->checkBoxEnergia->setChecked(false);
    ui->checkBoxMaterial->isEnabled() ? ui->checkBoxMaterial->setChecked(true) : ui->checkBoxMaterial->setChecked(false);
    ui->checkBoxMaldad->isEnabled() ? ui->checkBoxMaldad->setChecked(true) : ui->checkBoxMaldad->setChecked(false);
    ui->btnPausa->setEnabled(true);
    ui->btnResumir->setEnabled(false);
}


void MainWindow::on_btnDetener_clicked()
{
    QFile archivoColaMonstruos("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraColaMonstruos.txt");
    if (archivoColaMonstruos.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoColaMonstruos.resize(0);
        archivoColaMonstruos.close();
    }

    QFile archivoBasurero("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraBasureroDeMonstruos.txt");
    if (archivoBasurero.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoBasurero.resize(0);
        archivoBasurero.close();
    }

    QFile archivoHorno("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraHorno.txt");
    if (archivoHorno.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoHorno.resize(0);
        archivoHorno.close();
    }

    QFile archivoRobot1("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraRobot1.txt");
    if (archivoRobot1.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoRobot1.resize(0);
        archivoRobot1.close();
    }

    QFile archivoRobot2("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraRobot2.txt");
    if (archivoRobot2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoRobot2.resize(0);
        archivoRobot2.close();
    }

    QFile archivoAlmacen("C:\\Users\\Proyecto Diseño\\Desktop\\testingMonsterFaact\\bitacoraAlmacen.txt");
    if (archivoAlmacen.open(QIODevice::WriteOnly | QIODevice::Text)) {
        archivoAlmacen.resize(0);
        archivoAlmacen.close();
    }



}

