#ifndef _PERIOD_H_
#define _PERIOD_H_

#include <string>
#include <time.h>


class Period {
    tm startDate;
    tm endDate;
public:
    Period(tm firstDateVal, tm secDateVal);
    void showInfo();
    bool isDateInPeriod(tm dateToCheck);
    bool isOverlapPeriod(Period periodToCheck);
    bool isInsidePeriod(Period periodToCheck);
};
tm toTM(int dd, int mm, int yy);

#endif