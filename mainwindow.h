#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer_alarm_element.h"

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
    void new_element_created();

private slots:
    void on_actionTimer_triggered();

    void on_actionAlarm_Clock_triggered();

    void on_confirm_button_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
