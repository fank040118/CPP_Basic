#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

Clock::Clock() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// 类的成员函数中可以使用另一个成员函数，例如在此处，若时间的值
// 不合理时，可以呼叫默认的构建函数使对象的值被设置为默认值，
// 而不需要再写一遍默认构造函数的代码
// 由于函数定义时就已经写上了解析符::，所以函数内部呼叫另一个函数
// 时并不需要再写为Car::Car()
Clock::Clock(int hh, int mm, int ss){
    if (hh>=0 && hh<24 && mm>=0 && mm<60 && ss>=0 && ss<60){
        hours = hh;
        minutes = mm;
        seconds = ss;
    }    
    else{
        cout << "Invalid time!" << endl;
        Clock();
    }
}

void Clock::setClock(int hh, int mm, int ss){
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


void Clock::incrementSeconds(int sec){
    seconds = seconds + sec;
    adjustClock();
}
void Clock::incrementMinutes(int min){
    minutes = minutes + min;
    adjustClock();
}
void Clock::incrementHours(int hh){
    hours = hours + hh;
    adjustClock();
}
void Clock::addTime(Clock C){
    seconds = seconds + C.seconds;
    minutes = minutes + C.minutes;
    hours = hours + C.hours;
    adjustClock();
}

void Clock::printTime() const{
    if (hours < 10){ cout << "0" << hours << ":";}
    else{ cout << hours << ":"; }
    if (minutes < 10){ cout << "0" << minutes << ":"; }
    else{ cout << minutes << ":"; }
    if (seconds < 10){ cout << "0" << seconds << endl; }
    else{ cout << seconds << endl; }
}

// 当我们需要使用其他同类对象的数据成员时，我们可以在函数处定义
// 另一个对象在函数中的名称，并且可以直接使用点操作符调用其
// 数据成员或成员函数
int Clock::compareTime(Clock C) const {
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


void Clock::adjustClock(){
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