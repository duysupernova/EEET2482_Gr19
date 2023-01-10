#ifndef _REQUEST_H_
#define _REQUEST_H_


#include "period.h"
#include "member.h"
#include <string>

class Request {
    Period periodToOccupy;
    string memberWantToOccupy;
    bool isAccepted;
public:
    Request(string memberVal="", Period period=Period(1,1,1,1,1,1), bool isAcceptVal = false);
    string toString();
    void showInfo();


    string &getMemberToOccupy();
    Period &getPeriod();
    bool &getIsAccept();
    
    void setIsAccept(bool accept);
};



#endif