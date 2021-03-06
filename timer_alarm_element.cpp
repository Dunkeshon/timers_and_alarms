#include "timer_alarm_element.h"

timer_alarm_element::timer_alarm_element()
{

}

timer_alarm_element::timer_alarm_element(int time,bool is_timer,QUrl Audio_path)
{
    _time_in_miliseconds= time;
    _is_timer=is_timer;
    _audio_path=Audio_path;
    _is_active = false;
    _group= "not_setted";
    if(is_timer){
        _icon_path =":/images/timer_icon_blue.png";
    }
    else{
        _icon_path = ":/images/alarm_icon_blue.png";
    }

}

timer_alarm_element::timer_alarm_element(const timer_alarm_element & obj)
{
    _time_in_miliseconds=obj._time_in_miliseconds;
    _is_timer=obj._is_timer;
    _is_active=obj._is_active;
    _audio_path=obj._audio_path;
    _icon_path=obj._icon_path;
    _group=obj._group;
}

void timer_alarm_element::Set_time_in_miliseconds(int time_in_miliseconds)
{
    _time_in_miliseconds=time_in_miliseconds;
}


void timer_alarm_element::Set_is_timer(bool is_timer)
{
    _is_timer=is_timer;
}

void timer_alarm_element::Set_audio_path(QString audio_path)
{
    _audio_path=audio_path;
}

void timer_alarm_element::Set_icon_path(QString icon_path)
{
    _icon_path=icon_path;
}

void timer_alarm_element::Set_group(QString group)
{
    _group=group;
}

void timer_alarm_element::Set_is_active(bool active)
{
    _is_active=active;
}

int timer_alarm_element::time_in_miliseconds() const
{
    return _time_in_miliseconds;
}


bool timer_alarm_element::is_timer() const
{
     return _is_timer;
}

QUrl timer_alarm_element::audio_path() const
{
     return _audio_path;
}

QString timer_alarm_element::icon_path() const
{
    return _icon_path;
}

QString timer_alarm_element::group() const
{
    return _group;
}


bool timer_alarm_element::is_active() const
{
    return _is_active;
}

