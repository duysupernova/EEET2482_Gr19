#ifndef _REQUEST_H_
#define _REQUEST_H_


#include "period.h"
#include "member.h"
#include <string>

class Request {
    Period periodToOccupy;
    Member *memberWantToOccupy;
public:
    Request(Member *memberVal, Period period);

    string toString();
};



#endif