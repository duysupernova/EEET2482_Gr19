#include <string>
#include <time.h>
#include <iostream>
#include <cstring>
#include "period.h"
using std::cout;
using std::string;
using std::strcat;

/*DEFINITIONS*/
// Constructor
Period::Period(tm firstDateVal,tm secDateVal){
/*
Automatically adjust which date is start and end
Is slower
*/
    if(difftime(mktime(&firstDateVal),mktime(&secDateVal))<0){
        this->startDate = firstDateVal;
        this->endDate = secDateVal;
    } else {
        this->startDate = secDateVal;
        this->endDate = firstDateVal;
    }
}
// Overloaded functions for integer parameter
Period::Period(int startDay,int startMth, int startY, int endDay, int endMth, int endY){
    Period(toTM(startDay,startMth,startY),toTM(endDay,endMth,endY));
}

void Period::showInfo(){
    char* startInfo = new char[9];
    char* endInfo = new char[9];
    char timeFormat[20] =  "%A %b%d %Y";
    strftime(startInfo,50,timeFormat,&startDate);
    strftime(endInfo,50,timeFormat,&endDate);
    std::cout << "Period: " << startInfo << " --> " << endInfo << "\n";
}

string Period::toString(){
    char* startInfo = new char[9];
    char* endInfo = new char[9];
    char timeFormat[20] =  "%d/%M/%Y";
    strftime(startInfo,50,timeFormat,&startDate);
    strftime(endInfo,50,timeFormat,&endDate);
    char divide[] = "/";
    return std::strcat(startInfo, strcat(divide,endInfo) );
}

bool Period::isDateInPeriod(tm dateToCheck){                                 // Including start and date
    return (difftime(mktime(&startDate),mktime(&dateToCheck)) <= 0       // difftime return negative double if the first date is sooner
            && difftime(mktime(&dateToCheck),mktime(&endDate)) <= 0);    // Is the date between start and date 
}
bool Period::isOverlapPeriod(Period periodToCheck){                                     // Focus on the false cases ; INCLUDE start end date
    /* For remove occupied period function*/
    return !(difftime(mktime(&periodToCheck.endDate),mktime(&this->startDate))<0            //   ___0--X____START--END_____
            || difftime(mktime(&this->endDate),mktime(&periodToCheck.startDate))<0);        //   ___START--END____0--X____
}
bool Period::isInsidePeriod(Period periodToCheck){                                      
    /* For find suitable period function*/
    return (difftime(mktime(&this->startDate),mktime(&periodToCheck.startDate))<=0           //  ____START---0==X---END_____
            && difftime(mktime(&periodToCheck.endDate),mktime(&this->endDate))<=0);        
}


tm toTM(int dd, int mm, int yy){
    time_t rawTime = time(NULL);             //Without raw time, localtime function doesnt work
    struct tm timeValue;                   
    timeValue = *localtime(&rawTime);        // Have to assign some value but can modify later
    timeValue.tm_mday = dd;
    timeValue.tm_mon = mm-1;
    timeValue.tm_year = yy-1900;
    mktime(&timeValue);                      //Deduce other infos of timeValue for more cool displays (Get weekday,etc)
    return timeValue;
}

int main() {
    Period period1(toTM(11,12,2022),toTM(16,12,2022));
    Period period2(toTM(10,12,2022),toTM(14,12,2022));
    period1.showInfo();

    time_t now = time(NULL);
    struct tm nowlocal = *localtime(&now);

    cout << period1.isDateInPeriod(nowlocal) << "\n";
    cout << period2.isOverlapPeriod(period1) << "\n";

    cout << period1.toString();
/*    //Test the difftime function
    time_t now; 
    struct tm newyear; 
    struct tm sometime;
    double seconds;
    time(&now);  // get current time; same as: now = time(NULL)  
    newyear = *localtime(&now);
    sometime = *localtime(&now);
    newyear.tm_mday = 0;
    newyear.tm_mon = 0;  
    newyear.tm_year = 200;
    sometime.tm_mday = 0;
    sometime.tm_mon = 1;  
    sometime.tm_year = 200;
    seconds = difftime(mktime(&newyear),mktime(&sometime));             
    printf ("%.f diffrence between 2 times\n", seconds);
/**/
    return 0;
}
