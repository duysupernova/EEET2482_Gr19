#include "Request.h"



using std::string;

Request::Request(string memberVal, Period period,bool isAcceptVal):
    memberWantToOccupy(memberVal),periodToOccupy(period),isAccepted(isAcceptVal) {};

string Request::toString(){
    string stringAccept = isAccepted? "1" : "0";
    return memberWantToOccupy + "~" + periodToOccupy.toString() + "~" + stringAccept;
}

// int main() {
//     Member m1;
//     Request r1(&m1,Period(21,11,2022,27,11,2022));

//     return 0;
// }