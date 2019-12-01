#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer_alarm_element.h"
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::vector<timer_alarm_element*> My_timers_and_alarms;
    ~MainWindow();
signals:
    void new_element_created(); // created

private slots:
    void on_actionTimer_triggered(); // add timer

    void on_actionAlarm_Clock_triggered(); // add alarm

    void on_confirm_button_clicked(); // confirm adding

    void adding_to_list();// create timer/alarm,add it to vector of timers and add it to ui list
private:
    Ui::MainWindow *ui;
    std::vector<timer_alarm_element> time_element;  // stores info about timer/alarm
    bool changed;
};
#endif // MAINWINDOW_H
