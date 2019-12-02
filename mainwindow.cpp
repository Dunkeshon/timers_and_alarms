#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QMediaPlayer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->container->setEnabled(false); // true also when changed
    changed = false;
    connect(this,&MainWindow::new_element_created,this,&MainWindow::adding_to_list);
    connect(this,&MainWindow::start_countdown,this,&MainWindow::countdown);
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
/*
 * brief Starts countdown of timer or an alarm
 * details If it is an alarm clock - countdown miliseconds of alarm - miliseconds of current time
 */
void MainWindow::countdown()
{
    int time_to_count;
    QString message;
    QTimer *timer = new QTimer(this);
    timer_alarm_element *element = &time_element[ui->listWidget->currentRow()];
    if(element->is_timer()){ // if timer
        time_to_count=element->time_in_miliseconds();
        message = "Timer is over";
        ui->listWidget->currentItem()->setBackgroundColor("red");
    }
    else{ // if alarm
        QTime current_time= QTime::currentTime();
        time_to_count = element->time_in_miliseconds() - current_time.msecsSinceStartOfDay() ;
        message ="Alarm is over";
        ui->listWidget->currentItem()->setBackgroundColor("grey");
    }
    element->Set_is_active(true);
     timer->singleShot( time_to_count, this ,[=](){
        QString messages[2]{"Timer is over","Alarm is over"};
        QMessageBox ::warning(this,message,
                              "<p align=center> "+ message + "<p>"
                               "<br> Press OK to continue" ,QMessageBox::Ok);
        element->Set_is_active(false);


    });
    timer->start(time_to_count);
}

/*
 * signal Adding to the list
 */
void MainWindow::adding_to_list()
{
    bool _tmp_is_timer;
    if(ui->Creation_of_type->text()=="Timer"){
        if(ui->TimeSelection->time().msecsSinceStartOfDay()==0){
            QMessageBox::warning(this,"no time setted","You didn't set time.Try again");
            return;
        }
        _tmp_is_timer = true;
    }
    else{
        _tmp_is_timer = false;
    }
    //add to vector

    time_element.push_back(timer_alarm_element(ui->TimeSelection->time().msecsSinceStartOfDay(),_tmp_is_timer,":/sounds/music/WAKE_ME_UP.mp3"));

    QListWidgetItem * item = new QListWidgetItem(QIcon(time_element.back().icon_path()),
                                                 QTime(0,0,0).addMSecs(time_element.back().time_in_miliseconds()).toString("hh:mm:ss"));
    ui->listWidget->setIconSize(QSize(24, 24));
    QFont newFont("Courier", 24, QFont::Bold, false);
    item->setFont(newFont);
    //item->setTextColor("black");
    ui->listWidget->addItem(item);
}

/*
 * deleting from listwidget and from vector
 * PLANS : maybe it's a good idea to have dialog window
 * that asks if i want to delete for sure
 */
void MainWindow::on_pushButton_2_clicked()
{
    int _el_to_delete = ui->listWidget->currentRow();
    time_element.erase(time_element.begin()+_el_to_delete);
    ui->listWidget->takeItem(ui->listWidget->currentRow());

    //DEBUG
//    for (const auto &i : time_element) {
//            qDebug() << QTime(0,0,0).addMSecs(i.time_in_miliseconds).toString("hh:mm:ss");
//            qDebug() << " timer left ";
//    }

}

void MainWindow::on_startbutton_pressed()
{
    if(time_element[ui->listWidget->currentRow()].is_active()==false){
        emit(start_countdown());
    }
}

/*
 * starting timer/alarm
 */

//void MainWindow::on_startbutton_clicked()
//{
//    if(time_element[ui->listWidget->currentRow()].is_active()==false){
//        emit(start_countdown());
//    }
//    //choosen element -> start (emit signal start timer )
//}
