#ifndef _MENU_H_
#define _MENU_H_
#include "Member.h"
#include "House.h"
#include  "Admin.h"
#include <vector>

class Menu{
    public:
    void guestMenu(vector<Member> &memberVec,vector<House> &houseVec);
    void memberMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec);
    void adminMenu(vector<Member> &memberVec,vector<House> &houseVec);
    void mainMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec);

    // MAIN MENUS
    void adminLogin(vector<Member> &memberVec,vector<House> &houseVec);
    void checkLogin(vector<Member> &memberVec,vector<House> &houseVec);
    // GUEST MENUS
    void showHousesInfoMini(vector<House> &houseVec);
    void registerAccount(vector<Member> &memberVec,vector<House> &houseVec);
};

#endif