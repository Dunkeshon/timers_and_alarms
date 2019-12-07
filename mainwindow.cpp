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
    ui->TimeSelection->setDisplayFormat("hh:mm:ss");
    QTimer *update_timer = new QTimer(this);
    ui->container->setEnabled(false); // true also when changed
    changed = false;
    connect(this,&MainWindow::new_element_created,this,&MainWindow::adding_to_list);
    connect(this,&MainWindow::start_countdown,this,&MainWindow::countdown);
    connect(update_timer,&QTimer::timeout,this,&MainWindow::updating_time_of_timers );
    update_timer->start(1000);
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
    ui->TimeSelection->setTime(QTime(0,0,0));
    ui->container->setEnabled(false);
}
/*
 * brief Starts countdown of timer or an alarm
 * details If it is an alarm clock - countdown miliseconds of alarm - miliseconds of current time
 */
void MainWindow::countdown()
{
    QMediaPlayer *player = new QMediaPlayer;
    int time_to_count;
    QString message;
    QTimer *timer = new QTimer(this);
    int list_index = ui->listWidget->currentRow();
    timer_alarm_element *element = &time_element[list_index];

    element->Set_is_active(true);

    if(element->is_timer()){ // if timer
        time_to_count=element->time_in_miliseconds();

        message = "Timer is over";
        //ui->listWidget->currentItem()->setBackgroundColor("red");
    }
    else{ // if alarm
        QTime current_time= QTime::currentTime();
        time_to_count = element->time_in_miliseconds() - current_time.msecsSinceStartOfDay() ;
        message ="Alarm is over";
        player->setMedia(QUrl::fromLocalFile(element->audio_path()));
        player->setVolume(50);
        //ui->listWidget->currentItem()->setBackgroundColor("grey");
    }

        timer->singleShot( time_to_count, this ,[=](){
        element->Set_is_active(false);
     //   ui->listWidget->currentItem()->setText(QTime(0,0,0).toString());
        player->play();

        QMessageBox ::warning(this,message,
                              "<p align=center> "+ message + "<p>"
                               "<br> Press OK to continue" ,QMessageBox::Ok);
        //ПЕРЕМЕННАЯ ТИПА ЦВЕТ(стринг сначала сохранить а потом его возобновить)
       // ui->listWidget->item(list_index)->backgroundColor() = QWidget::palette().color(QWidget::backgroundRole());
        ui->listWidget->item(list_index)->setText(QTime(0,0,0).addMSecs(element->time_in_miliseconds()).toString());
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
        if(ui->TimeSelection->time().msecsSinceStartOfDay() == 0){
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
                                                 QTime(0,0,0).addMSecs(time_element.back().time_in_miliseconds()).toString());
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
/*
 * starting timer/alarm
 */
void MainWindow::on_startbutton_pressed()
{
    if(time_element[ui->listWidget->currentRow()].is_active()==false){
        emit(start_countdown());
    }
}

void MainWindow::updating_time_of_timers()
{
    QTime _current_changes_of_time;
    int _current_ms;
    timer_alarm_element *_curr_element;
    for (unsigned int i = 0;i<time_element.size();i++) {
        _curr_element=&time_element[i];
        if(_curr_element->is_timer() && _curr_element->is_active()){
        _current_changes_of_time =QTime::fromString(ui->listWidget->item(i)->text());
        _current_ms = _current_changes_of_time.msecsSinceStartOfDay();
        if(_current_ms!=0){
            ui->listWidget->item(i)->setText(QTime(0,0,0).addMSecs(_current_ms-1000).toString());
            }
        }
    }
}




