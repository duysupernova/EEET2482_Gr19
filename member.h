#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::cin;

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
    string &getFullName();
    string &getUserName();
    string &getPassword();
    int &getPhoneNumber();
    int &getCreditPoint();
    double &getOccupierScore();
    int &getNumOfRatings();

    void showInfo();
    /* 
    Custom functions for the program
    */
    void login_form();
    // FUNCTIONS for the renter
    void requestToOccupy(string houseId,int sd,int sm,int sy,int ed, int em,int ey);
    void reviewHouse(House &House,string reviewString);
    void calOcuNewScore(int temp);

    // FUNCTIONS for the owner

    friend class House;
    friend void saveToFile(string fileName, vector<House> &houseVec, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect,vector<House> &houseVect, char fDelimit);
};

#endif