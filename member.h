#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::string;
using std::cout;

// class Guest{
//     private:
//     string guestFullName;
//     string guestUserName;
//     string guestPassword;
//     int guestPhone;
//     public:
//     Guest(string guestFullName = " ", string guestUserName = " ", string guestPassword = " ", int guestPhoneVal = 0) : guestFullName(guestFullName), guestUserName(guestUserName), 
//                                                                                                 guestPassword(guestPassword), guestPhone(guestPhoneVal){};
//     void register_form();
//     void display_house();
// };
class House;
class Member {
private:
    string fullName;
    string userName;
    string password;
    int phoneNumber;
    int creditPoint;
    int occupierRatingScore;
public:
    // Constructor for object member
    Member(string fullNameVal = "", string userNameVal = "", string passwordVal = "",  int phoneVal = 0, int creditPointVal = 500, int occupierRatingScoreVal = 0);
    // GETTERS
    string &getFullName();
    string &getUserName();
    string &getPassword();
    int &getPhoneNumber();
    int &getCreditPoint();
    int &getOccupierScore();

    void showInfo();
    // Custom functions for the program
    void login_form();
    void requestToOccupy(string houseId,int sd,int sm,int sy,int ed, int em,int ey);

    friend void saveToFile(string fileName, vector<House> &houseArr, string firstDelimiter, string secDelimiter);
};




#endif