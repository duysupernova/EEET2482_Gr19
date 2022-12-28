#ifndef _PERIOD_H_
#define _PERIOD_H_

#include <string>
#include <time.h>
using std::string;

class Period {
    tm startDate;
    tm endDate;
public:
    Period(tm firstDateVal, tm secDateVal);
    Period(int startDay,int startMnt, int startY, int endDay, int endMnt, int endY);
    void showInfo();
    string toString();
    bool isDateInPeriod(tm dateToCheck);
    bool isOverlapPeriod(Period periodToCheck);
    bool isInsidePeriod(Period periodToCheck);
};
tm toTM(int dd, int mm, int yy);

#endif