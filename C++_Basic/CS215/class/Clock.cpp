#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

int Clock :: getHours() const {
    return hours;
}

int Clock :: getMinutes() const {
    return minutes;
}

int Clock :: getSeconds() const {
    return seconds;
}

Clock :: Clock() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Clock :: Clock(int hh, int mm, int ss){
    hours = hh;
    minutes = mm;
    seconds = ss;
    if (seconds >= 60 || seconds < 0){
        seconds = 0;
        cout << "Invalid time!" << endl;
    }
    if (minutes >= 60 || minutes < 0){
        minutes = 0;
        cout << "Invalid time!" << endl;
    }
    if (hours >= 24 || hours < 0){
        hours = 0;
        cout << "Invalid time!" << endl;
    }
}



void Clock :: setClock(int hh, int mm, int ss){
    hours = hh;
    minutes = mm;
    seconds = ss;
    if (seconds >= 60 || seconds < 0){
        seconds = 0;
        cout << "Invalid time!" << endl;
    }
    if (minutes >= 60 || minutes < 0){
        minutes = 0;
        cout << "Invalid time!" << endl;
    }
    if (hours >= 24 || hours < 0){
        hours = 0;
        cout << "Invalid time!" << endl;
    }
}

void Clock :: incrementSeconds(int sec){
    seconds = seconds + sec;
    adjustClock();
}

void Clock :: incrementMinutes(int min){
    minutes = minutes + min;
    adjustClock();
}

void Clock :: incrementHours(int hh){
    hours = hours + hh;
    adjustClock();
}

void Clock :: addTime(Clock C){
    seconds = seconds + C.getSeconds();
    minutes = minutes + C.getMinutes();
    hours = hours + C.getHours();
    adjustClock();
}

void Clock :: printTime() const{
    if (hours < 10){ cout << "0" << hours << ":";}
    else{ cout << hours << ":"; }
    if (minutes < 10){ cout << "0" << minutes << ":"; }
    else{ cout << minutes << ":"; }
    if (seconds < 10){ cout << "0" << seconds << endl; }
    else{ cout << seconds << endl; }
}

int Clock :: compareTime(Clock C) const {
    if (hours > C.getHours()) {
        return 1;
    }
    else if (hours < C.getHours()) {
        return -1;
    }
    if (minutes > C.getMinutes()) {
        return 1;
    }
    else if (minutes < C.getMinutes()) {
        return -1;
    }
    if (seconds > C.getSeconds()) {
        return 1;
    }
    else if (seconds < C.getSeconds()) {
        return -1;
    }

    return 0;
}

//-------------------------------------------
void Clock :: adjustClock(){
    if(seconds >= 60){
        minutes = minutes + (seconds/60);
        seconds = seconds % 60;
    }
    if(minutes >= 60){
        hours = hours + (minutes/60);
        minutes = minutes % 60;
    }
    if(hours >= 24){
        hours = hours % 24;
    }
}