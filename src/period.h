#ifndef _PERIOD_H_
#define _PERIOD_H_

#include <string>
#include <time.h>
#include <iostream>
#include <cstring>
using std::cout;
using std::strcat;
using std::string;

class Period {
    tm startDate;
    tm endDate;
public:
    Period(tm firstDateVal, tm secDateVal);
    Period(int startDay,int startMth, int startY, int endDay, int endMth, int endY);
    void showInfo();
    string toString();
    int length();
    bool isDateInPeriod(tm dateToCheck);
    bool isOverlapPeriod(Period periodToCheck);
    bool isInsidePeriod(Period periodToCheck);
};
tm toTM(int dd, int mm, int yy);

#endif