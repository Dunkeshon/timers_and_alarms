#ifndef TIMER_ALARM_ELEMENT_H
#define TIMER_ALARM_ELEMENT_H

#include <QObject>
#include <vector>

class timer_alarm_element
{
public:
    timer_alarm_element(int time,bool is_timer,QString Audio_path);
    int time_in_miliseconds;
    bool is_timer;
    QString audio_path;
    QString icon_path;
    bool is_active;
};

#endif // TIMER_ALARM_ELEMENT_H
