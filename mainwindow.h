#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer_alarm_element.h"
#include <vector>
#include <QFileDialog>
#include <QCloseEvent>
#include "donotdisturb.h"
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int do_not_distorb_from;
    int do_not_distorb_to;
    QString display_format;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void new_element_created(); // created in edit window
    void start_countdown(); // pressed on start button
    void do_not_disturb_changed();
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

    void on_actionset_change_don_t_disturb_time_triggered();

    void change_ui_disturb();

    void on_dont_disturb_check_clicked(bool checked);

    void on_actionhh_mm_Am_Pm_triggered();

    void on_actionhh_mm_ss_Am_Pm_triggered();

    void on_actionhh_mm_triggered();

    void on_actionhh_mm_ss_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<timer_alarm_element> time_element;  // stores info about timer/alarm
    bool changed;
    QUrl _temp_adress_of_audio;
    DoNotDisturb *child;
};
#endif // MAINWINDOW_H
