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
           int minOccupierVal = 0, int ptVal = 0, Period period = Period(1,1,1,1,1,1), vector<string> reviews={}, vector<Request> requests={}); 
    Member *getOwner();
    void setOwner(Member* member);
    void showHouseInfo();
    void showInfoFull();
    void showInfoMini();
    // void getCity();//
    // void getLocation();
    // void getDescription();
    void getUserReview();
    void getHouseRating(int temp);
    Period &getPeriodForOccupy();

    /*  HOUSE OWNERS menus */
    void registerHouseMenu();
    void listHouse();
    void unlistHouse(); 
    void viewRequest();
    void acceptRequest();
    void rateOccupier(vector<House> &houseVec);
    /*  RENTERS menus */
    void addRequest(Request requestToAdd);
    void addReview(Member *member, string reviewString);
    void sreachHouse(vector<House> &houseVec);
    void requestToOccupy();
    void checkIfQualify(Member member);


    friend void saveToFile(string fileName, vector<House> &houseArr, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect, vector<House> &houseVect, char fDelimit);
};

#endif
