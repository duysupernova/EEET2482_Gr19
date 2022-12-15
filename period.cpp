#include <string>
#include <time.h>
#include <iostream>
using std::cout;
using std::string;

class Period {
    tm startDate;
    tm endDate;
public:
    Period(tm startDateVal,tm EndDateVal){
    /*
    Format is dd/mm/yy
    */
   this->startDate = startDateVal;
   this->endDate = EndDateVal;
}
    void showInfo(){
        char* startInfo = new char[9];
        char* endInfo = new char[9];
        char timeFormat[20] =  "%A %b%d %Y";
        strftime(startInfo,50,timeFormat,&startDate);
        strftime(endInfo,50,timeFormat,&endDate);
        std::cout << "Period: " << startInfo << " --> " << endInfo;
    }
};

tm toTimeObj(int dd, int mm, int yy){
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
    Period period1(toTimeObj(11,11,2022),toTimeObj(22,11,2022));
    period1.showInfo();
    return 0;
}
