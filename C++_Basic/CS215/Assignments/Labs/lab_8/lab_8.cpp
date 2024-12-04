/*
Course: CS215_401
Project: Lab8
Purpose: test clock class created by student
Author: Anthony(Zijian) Wang
*/
#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

// g++ lab_8.cpp Clock.cpp -o lab_8
// ./lab_8

int main() {
    // Write each statement for each operation below in ().
    
    //(create Clock object C1)
    Clock C1;
    //(set C1 with h : m : s = 3 : -5 : 16)
    C1.setClock(3,-5,16);
    //(set C1 with h : m : s = 0 : 0 : 5)
    C1.setClock(0,0,5);
    //(create second Clock object C2 with h:m:s = 12:35:59)
    Clock C2;
    C2.setClock(12,35,59);
    //(print C1)
    cout << "Clock C1 -- " ;
    C1.printTime();
    //(print C2)
    cout << "Clock C2 -- ";
    C2.printTime();
    
    // Compare C1 with C2.
    if (C1.compareTime(C2) < 0) {
        cout << "C1 is earlier than C2" << endl;
    } else if (C1.compareTime(C2) > 0) {
        cout << "C1 is later than C2" << endl;
    } else {
        cout << "C1 is the same as C2" << endl;
    }

    //(add C2 into C1)
    C1.addTime(C2);
    //(print C1)
    cout << "Clock C1 -- " ;
    C1.printTime();
    //(print C2)
    cout << "Clock C2 -- " ;
    C2.printTime();

    //(compare C1 with C2)
    if (C1.compareTime(C2) < 0) {
        cout << "C1 is earlier than C2" << endl;
    } else if (C1.compareTime(C2) > 0) {
        cout << "C1 is later than C2" << endl;
    } else {
        cout << "C1 is the same as C2" << endl;
    }

    //(increase clock C1 by 55 seconds)
    C1.incrementSeconds(55);
    //(print C1)
    cout << "Clock C1 -- " ;
    C1.printTime();
    //(increase clock C1 by 119 minutes)
    C1.incrementMinutes(119);
    //(print C1)
    cout << "Clock C1 -- " ;
    C1.printTime();
    //(increase clock C1 by 22 hours)
    C1.incrementHours(22);
    //(print C1)
    cout << "Clock C1 -- " ;
    C1.printTime();
    //(print C2)
    cout << "Clock C2 -- " ;
    C2.printTime();

    // Compare C2 with C1.
    if (C2.compareTime(C1) < 0)
        cout << "C2 is earlier than C1" << endl;
    else if (C2.compareTime(C1) > 0)
        cout << "C2 is later than C1" << endl;
    else
        cout << "C2 is the same as C1" << endl;

    return 0;
}
