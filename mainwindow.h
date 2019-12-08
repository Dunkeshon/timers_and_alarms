#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer_alarm_element.h"
#include <vector>
#include <QFileDialog>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void new_element_created(); // created in edit window
    void start_countdown(); // pressed on start button

private slots:

    void on_actionTimer_triggered(); // add timer

    void on_actionAlarm_Clock_triggered(); // add alarm

    void on_confirm_button_clicked(); // confirm adding

    void countdown(); //starting countdown of a timer

    void adding_to_list();// create timer/alarm,add it to vector of timers and add it to ui list

    void on_pushButton_2_clicked();

    void on_startbutton_pressed();

    void updating_time_of_timers(); // updating time every second in started timers

    void on_choose_sound_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    std::vector<timer_alarm_element> time_element;  // stores info about timer/alarm
    bool changed;
    QUrl _temp_adress_of_audio;
};
#endif // MAINWINDOW_H
