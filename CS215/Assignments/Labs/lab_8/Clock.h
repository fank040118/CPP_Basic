/* File:    Clock.h
 * Course:  CS215-401
 * Project: Lab 8
 * Purpose: Provide the delcaration of the class named Clock.
 *			Note that it represents a 24-hour clock (also known as military time)
 * Author:  Anthony Wang
 */
#ifndef CLOCK_H
#define CLOCK_H

// define constants
const int HOUR_MIN_SEC = 60;
const int HOURS_TO_WRAP = 24;

class Clock {
public:

    // Default constructor.
    Clock();

    // Alternative constructor.
    // Should print error message if any of the parameters are
    // out of range.
    Clock(int hh, int mm, int ss);



    // Set time to hh:mm:ss.
    void setClock(int hh, int mm, int ss);

    // Increase time by `sec` seconds.
    void incrementSeconds(int sec);

    // Increase time by `min` minutes.
    void incrementMinutes(int min);

    // Increase time by `hh` hours, 
    // If hours reach 24, simply wrap around to 0.
    void incrementHours(int hh);

    // Add `C` to the current clock time.
    void addTime(Clock C);

    //print time in hours:minutes:seconds in 24-hour format
    void printTime() const;

    // Compare with C, if it is earlier than C, return -1.
    // If it is the same time as C, return 0.
    // If it is later than C, return 1.
    int compareTime(Clock C) const;

private:

    // Declare data members of the class.
    // 0 <= hours < 24, 0 <= minutes < 60, 0 <= seconds < 60
    int hours, minutes, seconds;

    // Helper function to ensure data members are adjusted to proper 24 hour
    // clock time.
    // It only serves the member functions of this class, hence
    // ``private''.
    void adjustClock();
};

#endif  /* CLOCK_H*/