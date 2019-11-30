#include "timer_alarm_element.h"

timer_alarm_element::timer_alarm_element(int time,bool is_timer,QString Audio_path)
{
    this->time_in_miliseconds=time;
    this->is_timer=is_timer;
    this->audio_path=Audio_path;
    this->is_active = false;
    if(is_timer){
        this->media_path =":/images/timer.png";
    }
    else{
        this->media_path = ":/images/alarm_icon.png";
    }

}
