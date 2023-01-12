#ifndef _ADMIN_H_
#define _ADMIN_H_
#include <iostream>
#include "house.h"
#include "member.h"

using std::cout;
using std::cin;
using std::string;

class Admin {
    public:

    void showHouseList(vector<House> &houseVec);
    void showMemberList(vector<Member> &memberVec);
};
#endif