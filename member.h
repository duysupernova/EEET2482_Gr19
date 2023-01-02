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
class Request;
class Member {
private:
    string fullName;
    string userName;
    string password;
    int phoneNumber;
    int creditPoint;
    double occupierRatingScore;
    int numOfRatings;
public:
    // Constructor for object member
    Member(string fullNameVal = "", string userNameVal = "", string passwordVal = "",  int phoneVal = 0, int creditPointVal = 500, double occupierRatingScoreVal = 0, int numOfRatingVal = 0);
    // GETTERS
    string getFullName();
    string getUserName();
    string getPassword();
    int getPhoneNumber();
    int getCreditPoint();
    double getOccupierScore();

    void showInfo();
    /* 
    Custom functions for the program
    */
    void login_form();
    // FUNCTIONS for the renter
    void requestToOccupy(string houseId,int sd,int sm,int sy,int ed, int em,int ey);
    void reviewHouse(House &House,string reviewString);
    // FUNCTIONS for the owner

    friend class House;
    friend void saveToFile(string fileName, vector<House> &houseVec, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect, vector<Request> &requestVect,  vector<House> &houseVect, char fDelimit, char sDelimit);
};




#endif