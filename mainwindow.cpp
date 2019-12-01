#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->container->setEnabled(false); // true also when changed
    changed = false;
    connect(this,&MainWindow::new_element_created,this,&MainWindow::adding_to_list);
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
    if( !changed ){
        emit(new_element_created()); // add to list
    }
//    else{
//        emit() // change element and set changed to false
//    }

    ui->Creation_of_type->setText(":')");
    ui->TimeSelection->setTime(QTime(0,0));
    ui->container->setEnabled(false);
}

void MainWindow::adding_to_list()
{
    bool _tmp_is_timer;
    if(ui->Creation_of_type->text()=="Timer"){
        _tmp_is_timer = true;
    }
    else{
        _tmp_is_timer = false;
    }
    //add to vector
    time_element.push_back(timer_alarm_element(ui->TimeSelection->time().msecsSinceStartOfDay(),_tmp_is_timer,":/sounds/music/WAKE_ME_UP.mp3"));
    QListWidgetItem * item = new QListWidgetItem(QIcon(time_element.back().icon_path),QTime(0,0,0).addMSecs(time_element.back().time_in_miliseconds).toString("hh:mm:ss"));
    //item->setTextColor("black");
    ui->listWidget->addItem(item);
}
