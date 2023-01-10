#include "Period.h"
/*DEFINITIONS*/
// Constructor
Period::Period(tm firstDateVal,tm secDateVal){
/*
Automatically adjust which date is start and end
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
    this->startDate = toTM(startDay,startMth,startY);
    this->endDate = toTM(endDay,endMth,endY);
    if(difftime(mktime(&startDate),mktime(&endDate))>0){
        this->endDate = toTM(startDay,startMth,startY);
        this->startDate = toTM(endDay,endMth,endY);
    }
}

void Period::showInfo(){
    char* startInfo = new char[9];
    char* endInfo = new char[9];
    char timeFormat[20] =  "%A %b%d %Y";
    strftime(startInfo,50,timeFormat,&startDate);
    strftime(endInfo,50,timeFormat,&endDate);
    std::cout << startInfo << " --> " << endInfo;
}

string Period::toString(){
    char* startInfo = new char[9];
    char* endInfo = new char[9];
    char timeFormat[20] =  "%d/%m/%Y";
    strftime(startInfo,50,timeFormat,&startDate);
    strftime(endInfo,50,timeFormat,&endDate);
    char divide[] = "/";
    return std::strcat(startInfo, strcat(divide,endInfo) );
}

int Period::length(){
    return difftime(mktime(&endDate),mktime(&startDate)) / 86400 + 1;  // 86400 is the total amount of seconds in a day
}

bool Period::isDateInPeriod(tm dateToCheck){                                 // Including start and date
    return (difftime(mktime(&startDate),mktime(&dateToCheck)) <= 0          // difftime return negative double if the first date is sooner
            && difftime(mktime(&dateToCheck),mktime(&endDate)) <= 0);       // Is the date between start and date 
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

// int main() {
//     Period period1(1,2,2023,2,2,2023);
//     Period period2(toTM(1,2,2023),toTM(2,3,2023));
//     period1.showInfo();
//     period2.showInfo();
//     time_t now = time(NULL);
//     struct tm nowlocal = *localtime(&now);

//     cout << period1.isDateInPeriod(nowlocal) << "\n";
//     cout << period1.isOverlapPeriod(period2) << "\n";
//     cout << period1.isInsidePeriod(period2) << "\n";
//     cout << period2.isInsidePeriod(period1) << "\n";

//     cout << period1.toString() << "\n";

//     cout << period1.length() << "\n";
//     cout << period2.length()<< "\n";

//     return 0;
// }
