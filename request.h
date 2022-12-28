#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "member.h"
#include "period.h"


class Request {
    Member memberWantToOccupy;
    Period periodToOccupy;
public:
    Request (Member &memberVal, Period period);

    string toString();
};



#endif