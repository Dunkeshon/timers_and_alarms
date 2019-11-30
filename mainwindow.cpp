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
    SetingTimerWindow * creation_window= new SetingTimerWindow;
    creation_window->show();

    bool is_timer= true;
    creation_window->ready_to_create_element(is_timer);
}

void MainWindow::on_actionAlarm_Clock_triggered()
{
    SetingTimerWindow * creation_window= new SetingTimerWindow;
    creation_window->show();
    bool is_timer= false;
    creation_window->ready_to_create_element(is_timer);
}
