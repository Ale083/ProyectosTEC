#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "energiathread.h"
#include "estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    cola<QString>* energiaCola;
    EnergiaThread* energiaThread;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
