#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    energiaCola = new cola<QString>();
    energiaThread = new EnergiaThread("Energia Thread 1",energiaCola,ui->lblColaEnergia,ui->lblCountdownEnergia,ui->sbxEnergia,ui->sbxCapacidadColaEnergia,ui->checkBoxEnergia,&mutexColaEnergia);
    energiaThread -> start();

    materialCola = new cola<QString>();
    materialThread = new MaterialThread("Material Thread 1",materialCola,ui->lblColaMaterial,ui->lblCountdownMaterial,ui->sbxMaterial,ui->sbxCapacidadColaMaterial,ui->checkBoxMaterial,&mutexColaMaterial);
    materialThread -> start();

    maldadCola = new cola<QString>();
    maldadThread = new MaldadThread("Maldad Thread 1", maldadCola, ui->lblColaMaldad, ui->lblCountdownMaldad, ui->sbxMaldad, ui->sbxCapacidadColaMaldad, ui->checkBoxMaldad,&mutexColaMaldad);
    maldadThread->start();

    colaDeMonstruos = new cola<Monstruo*>;
    basureroDeMonstruos = new Lista<Monstruo*>;
    combinarThread = new CombinarThread("Combinar Thread 1",energiaCola, materialCola, maldadCola, ui->lblCountdownCombinar,ui->sbxCombinar,ui->checkBoxCombinar,ui->lblColaMonstruos,ui->sbxCapacidadColaDeMonstruos,colaDeMonstruos,basureroDeMonstruos,&mutexColaEnergia,&mutexColaMaterial,&mutexColaMaldad, &mutexColaMonstruos);
    combinarThread -> start();

    refresh = new Refresh(energiaCola,materialCola,maldadCola,ui->lblColaEnergia,ui->sbxCapacidadColaEnergia,ui->lblColaMaterial, ui->sbxCapacidadColaMaterial, ui->lblColaMaldad, ui->sbxCapacidadColaMaldad, colaDeMonstruos, ui->lblColaMonstruos,ui->sbxCapacidadColaDeMonstruos,&mutexColaEnergia,&mutexColaMaterial,&mutexColaMaldad);
    refresh -> start();

    colaBandeja1 = new cola<Monstruo*>;
    colaBandeja2 = new cola<Monstruo*>;
    colaBandeja3 = new cola<Monstruo*>;
    colaBandeja4 = new cola<Monstruo*>;
    hornoThread = new HornoThread("Horno Thread 1", colaDeMonstruos, colaBandeja1, ui->checkBoxBandeja1, ui->lblContenido1, ui->sbxBandeja1, colaBandeja2, ui->checkBoxBandeja2, ui->lblContenido2, ui->sbxBandeja2, colaBandeja3, ui->checkBoxBandeja3, ui->lblContenido3, ui->sbxBandeja3, colaBandeja4, ui->checkBoxBandeja4, ui->lblContenido4, ui->sbxBandeja4, ui->lblCountdownHorno, ui->sbxHorno, &mutexColaMonstruos);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRefresh_clicked(){
    //energiaCola
    QLabel* lblColaEnergia = ui->lblColaEnergia;
    // QLabel* lblCountdownEnergia = ui->lblColaEnergia;
    QSpinBox* sbxCapacidadColaEnergia = ui->sbxCapacidadColaEnergia;
    QLabel* lblColaMaterial = ui->lblColaMaterial;
    // QLabel* lblCountdownMaterial = ui->lblColaMaterial;
    QSpinBox* sbxCapacidadColaMaterial = ui->sbxCapacidadColaMaterial;
    QLabel* lblColaMaldad = ui->lblColaMaldad;
    // QLabel* lblCountdownMaldad = ui->lblColaMaldad;
    QSpinBox* sbxCapacidadColaMaldad = ui->sbxCapacidadColaMaldad;
    QLabel* lblColaMonstruos = ui->lblColaMonstruos;
    QSpinBox* sbxCapacidadColaDeMonstruos = ui->sbxCapacidadColaDeMonstruos;

    lblColaMonstruos -> setText(QString::number(colaDeMonstruos->size()) + " de " + QString::number(sbxCapacidadColaDeMonstruos->value()));
    lblColaEnergia -> setText(QString::number(energiaCola->size()) + " de " + QString::number(sbxCapacidadColaEnergia->value()));
    lblColaMaterial -> setText(QString::number(materialCola->size()) + " de " + QString::number(sbxCapacidadColaMaterial->value()));
    lblColaMaldad -> setText(QString::number(maldadCola->size()) + " de " + QString::number(sbxCapacidadColaMaldad->value()));
}

