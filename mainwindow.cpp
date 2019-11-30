#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <setingtimerwindow.h>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->container->setEnabled(false); // true also when changed
//    connect(this,&MainWindow::new_element_created,[=](){
//    qDebug()<<"signal is working";
//    if()
//    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionTimer_triggered()
{
    // set is active ;
    // normal color ;
    ui->container->setEnabled(true);
    ui->Creation_of_type->setText("Timer");
    ui->TimeSelection->setTime(QTime(0,0));

}

void MainWindow::on_actionAlarm_Clock_triggered()
{
    ui->container->setEnabled(true);
    ui->Creation_of_type->setText("Alarm");
    ui->TimeSelection->setTime(QTime::currentTime());
}

void MainWindow::on_confirm_button_clicked()
{
     // give all the information to the vector of timers, push to the list if wasn't changed
    ui->Creation_of_type->setText(":')");
    ui->TimeSelection->setTime(QTime(0,0));
    ui->container->setEnabled(false);
}
