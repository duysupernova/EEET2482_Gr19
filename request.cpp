#include "Request.h"



using std::string;

Request::Request(string memberVal, Period period):
    memberWantToOccupy(memberVal),periodToOccupy(period){};

string Request::toString(){
    return memberWantToOccupy + "~" + periodToOccupy.toString();
}

// int main() {
//     Member m1;
//     Request r1(&m1,Period(21,11,2022,27,11,2022));

//     return 0;
// }