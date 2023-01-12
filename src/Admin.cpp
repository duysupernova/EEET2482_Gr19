
#include "Admin.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;



void Admin::showMemberList(vector<Member> &memberVec){
    string tempt;
    int index = 0;
    system("cls");
    cout << "**==All registered members==**\n";
    for (Member member : memberVec){
        cout << "\n[" << index+1 << "]";
        member.showInfo();
        index++;
    }
    cout << "\n\nPress a character and enter to continue!\n";
    cin >> tempt;
}

void Admin::showHouseList(vector<House> &houseVec){
    string tempt;
    int index = 0;
    system("cls");
    cout << "**==All registered house==**\n";
    for (House house : houseVec){
        cout << "[" << index+1 << "]\n";
        house.showHouseInfo();
        index ++;
    }
    cout << "\n\nPress a character and enter to continue!\n";
    cin >> tempt;
}

// int Admin::login_form(){
// int exist;
// string checkUsername, checkPassword;
// cout << "Please enter admin username: ";
// cin >> Ad_password;
// cout << "Please enter admin password: ";
// cin >> Ad_password;

// std::fstream AdminData;
// AdminData.open("AdminData.txt", std::ios::out);

// if (!AdminData) {
//     std::cerr << "Fail to create/open file \n";
//     return -1;
// }


    //Show member list


    //Show house list


