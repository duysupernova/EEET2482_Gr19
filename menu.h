#ifndef _MENU_H_
#define _MENU_H_
#include "Member.h"
#include "House.h"
#include <vector>

class Menu{
    public:
    void guestMenu();
    void memberMenu();
    void adminMenu();
    void mainMenu();
    void checkLogin(vector<Member> &memberVec);
    void registerAccount(vector<Member> &memberVec,vector<House> &houseVec);
};

#endif