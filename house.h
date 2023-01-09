#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "Member.h"             
#include "Period.h"
#include "Request.h"
#include <string>
#include <vector>
#include <cctype>
using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::isdigit;

class House{
private:
    string location;
    string description;
    string city;
    double houseRating;   
    int numOfRatings;
    double minOccupierRating;
    int ptPerDay;

    Period periodForOccupy;
    vector<string> userReviews;
    vector<Request> requestsToOccupy;
    Member* owner;

public:
    House(Member* owner = nullptr,string locationVal="", string descriptVal="", string cityVal="", double hRating=0, int numRating=0,
           int minOccupierVal = -10, int ptVal = 0, Period period = Period(1,1,1,1,1,1), vector<string> reviews={}, vector<Request> requests={}); 
    Member *getOwner();
    void setOwner(Member* member);
    void showHouseInfo();
    void showInfoFull();
    void showInfoMini();
    // void getCity();//
    // void getLocation();
    // void getDescription();
    Period &getPeriodForOccupy();

    /*  HOUSE OWNERS menus */
    void registerHouseMenu();
    void listHouse();
    void unlistHouse(); 
    void viewRequest();
    void addRequest(Request requestToAdd);
    void addReview(Member *member, string reviewString);
    void acceptRequest();
    void rateOccupier(vector<House> &houseVec);
    /*  RENTERS menus */
    void processHouseRating();
    void processUserReview(Member *member);
    void sreachHouse(vector<House> &houseVec);
    void checkIfQualify(Member member);
    void viewRequestsMade(vector<House> &houseVec);
    void rateHouse(vector<House> &houseVec);
    void reviewHouse(vector<House> &houseVec);


    friend void saveToFile(string fileName, vector<House> &houseArr, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect, vector<House> &houseVect, char fDelimit);
};

#endif
