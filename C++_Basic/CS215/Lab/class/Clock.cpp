#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;


// set clock as defalut
Clock :: Clock() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// set clock by user's input
Clock :: Clock(int hh, int mm, int ss){
    // set value as user's Input if input is not out of range
    if (hh>=0 && hh<24 && mm>=0 && mm<60 && ss>=0 && ss<60){
        hours = hh;
        minutes = mm;
        seconds = ss;
    }    
    // if input is invalid, set it back to 0
    else{
        cout << "Invalid time!" << endl;
        Clock();
    }
}



void Clock :: setClock(int hh, int mm, int ss){
    // set value as user's Input
    hours = hh;
    minutes = mm;
    seconds = ss;
    // if input is invalid, set it back to 0
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
    // add sec to seconds, call adjustClock to refresh time
    seconds = seconds + sec;
    adjustClock();
}

void Clock :: incrementMinutes(int min){
    // add min to minutes, call adjustClock to refresh time
    minutes = minutes + min;
    adjustClock();
}

void Clock :: incrementHours(int hh){
    // add hh to hours, call adjustClock to refresh time
    hours = hours + hh;
    adjustClock();
}

void Clock :: addTime(Clock C){
    // add values each by each, then call adjustClock
    seconds = seconds + C.seconds;
    minutes = minutes + C.minutes;
    hours = hours + C.hours;
    adjustClock();
}

void Clock :: printTime() const{
    // print time, if the value is less than 10, then
    // add a "0" before print it
    if (hours < 10){ cout << "0" << hours << ":";}
    else{ cout << hours << ":"; }
    if (minutes < 10){ cout << "0" << minutes << ":"; }
    else{ cout << minutes << ":"; }
    if (seconds < 10){ cout << "0" << seconds << endl; }
    else{ cout << seconds << endl; }
}

int Clock :: compareTime(Clock C) const {
    // compare value, if Hour is not same, return 1 / -1
    // if Hour is same, then go to next if to compare minutes
    // same gose to seconds
    // if all the value are same, then return 0(when all if are skipped)
    if (hours > C.hours)) {
        return 1;
    }
    else if (hours < C.hours) {
        return -1;
    }
    if (minutes > C.minutes) {
        return 1;
    }
    else if (minutes < C.minutes) {
        return -1;
    }
    if (seconds > C.seconds) {
        return 1;
    }
    else if (seconds < C.seconds) {
        return -1;
    }

    return 0;
}

//-------------------------------------------
void Clock :: adjustClock(){
    // adjust value, if it's larger than 60, set it to value%60
    // then add value/60 to next value.
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