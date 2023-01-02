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
class Member {
private:
    string fullName;
    string userName;
    string password;
    int phoneNumber;
    int creditPoint;
    double occupierRatingScore;
    int numOfOperating;
public:
    // Constructor for object member
    Member(string fullNameVal = "", string userNameVal = "", string passwordVal = "",  int phoneVal = 0, int creditPointVal = 500, double occupierRatingScoreVal = 0, int numOfOperating = 0);
    // GETTERS
    string &getFullName();
    string &getUserName();
    string &getPassword();
    int &getPhoneNumber();
    int &getCreditPoint();
    double &getOccupierScore();
    int &getNumOfOperating();
    void calOcuNewScore(int temp);
    void showInfo();
    void requestToOccupy(string houseId,int sd,int sm,int sy,int ed, int em,int ey);
    friend void saveToFile(string fileName, vector<House> &houseArr, string firstDelimiter, string secDelimiter);
};




#endif