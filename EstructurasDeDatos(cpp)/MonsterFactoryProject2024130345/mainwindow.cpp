#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    energiaCola = new cola<QString>();
    energiaThread = new EnergiaThread("Energia Thread 1",energiaCola,ui->lblColaEnergia,ui->lblCountdownEnergia,ui->sbxEnergia,ui->sbxCapacidadColaEnergia,ui->checkBoxEnergia);
    energiaThread -> start();

    materialCola = new cola<QString>();
    materialThread = new MaterialThread("Material Thread 1",materialCola,ui->lblColaMaterial,ui->lblCountdownMaterial,ui->sbxMaterial,ui->sbxCapacidadColaMaterial,ui->checkBoxMaterial);
    materialThread -> start();

    maldadCola = new cola<QString>();
    maldadThread = new MaldadThread("Maldad Thread 1", maldadCola, ui->lblColaMaldad, ui->lblCountdownMaldad, ui->sbxMaldad, ui->sbxCapacidadColaMaldad, ui->checkBoxMaldad);
    maldadThread->start();

    colaDeMonstruos = new cola<Monstruo*>;
    basureroDeMonstruos = new Lista<Monstruo*>;
    combinarThread = new CombinarThread("Combinar Thread 1",energiaCola, materialCola, maldadCola, ui->lblCountdownCombinar,ui->sbxCombinar,ui->checkBoxCombinar,ui->lblColaMonstruos,ui->sbxCapacidadColaDeMonstruos,colaDeMonstruos,basureroDeMonstruos);
    combinarThread -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
