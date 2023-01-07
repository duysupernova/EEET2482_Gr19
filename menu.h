#ifndef _MENU_H_
#define _MENU_H_
#include "Member.h"
#include "House.h"
#include <vector>

class Menu{
    public:
    void guestMenu(vector<Member> &memberVec,vector<House> &houseVec);
    void memberMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec);
    void adminMenu(vector<Member> &memberVec,vector<House> &houseVec);
    void mainMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec);

    // MAIN MENUS
    void checkLogin(vector<Member> &memberVec,vector<House> &houseVec);
    // GUEST MENUS
    void registerAccount(vector<Member> &memberVec,vector<House> &houseVec);
};

#endif