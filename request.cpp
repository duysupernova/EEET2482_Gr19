#include "request.h"
#include "member.h"
#include <string>

using std::string;

Request::Request (Member &memberVal, Period period):
    memberWantToOccupy(memberVal),periodToOccupy(period){};

string Request::toString(){
    return memberWantToOccupy.getUserName() + "&&" + periodToOccupy.toString();
}