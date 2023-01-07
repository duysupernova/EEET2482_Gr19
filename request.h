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
    Request(string memberVal, Period period, bool isAcceptVal);
    string toString();
    string &getMemberToOccupy();
    Period &getPeriod();
    void setIsAccept(bool accept);
};



#endif