#ifndef TIMER_ALARM_ELEMENT_H
#define TIMER_ALARM_ELEMENT_H

#include <QObject>
#include <vector>
#include <QFileDialog>
#include <QDataStream>

class timer_alarm_element
{
private:
     bool _is_active;
     int _time_in_miliseconds; // time of timer
     bool _is_timer;
     QUrl _audio_path;
     QString _icon_path;

public:

    timer_alarm_element();
    timer_alarm_element(int time,bool is_timer,QUrl Audio_path);
    timer_alarm_element(const timer_alarm_element &obj);
    void Set_time_in_miliseconds(int time_in_miliseconds);
    void Set_is_active(bool active);
    void Set_is_timer(bool is_timer);
    void Set_audio_path(QString audio_path);
    void Set_icon_path(QString icon_path );

    int time_in_miliseconds() const;
    int time_left_in_ms() const;
    bool is_active() const;
    bool is_timer() const;
    QUrl audio_path() const;
    QString icon_path() const;

    /* overload the operators */
        friend QDataStream &operator<< (QDataStream &out, const timer_alarm_element &rhs)
        {
            out << rhs._is_active << rhs._is_timer << rhs._icon_path << rhs._audio_path << rhs._time_in_miliseconds ;
            return out;
        }

        friend QDataStream &operator>> (QDataStream &in, timer_alarm_element &rhs)
        {
            in >> rhs._is_active >> rhs._is_timer >> rhs._icon_path >> rhs._audio_path >> rhs._time_in_miliseconds;
            return in;
        }



};

#endif // TIMER_ALARM_ELEMENT_H
