#ifndef TIMER_ALARM_ELEMENT_H
#define TIMER_ALARM_ELEMENT_H

#include <QObject>
#include <vector>

class timer_alarm_element
{
private:
     bool _is_active;
     int _time_in_miliseconds;
     bool _is_timer;
     QString _audio_path;
     QString _icon_path;
public:


    timer_alarm_element(int time,bool is_timer,QString Audio_path);
    timer_alarm_element(const timer_alarm_element &obj);
    void Set_time_in_miliseconds(int time_in_miliseconds);
    void Set_is_active(bool active);
    void Set_is_timer(bool is_timer);
    void Set_audio_path(QString audio_path);
    void Set_icon_path(QString icon_path );


    int time_in_miliseconds();
    bool is_active();
    bool is_timer();
    QString audio_path();
    QString icon_path( );



};

#endif // TIMER_ALARM_ELEMENT_H
