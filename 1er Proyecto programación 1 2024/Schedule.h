#pragma once
#include <iostream>
class Schedule
{
private:
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;

public:
    Schedule();
    void AssignSchedule(int day, int month, int year, int hour, int minute);
    void ShowSchedule();
    int getMinute();
};
