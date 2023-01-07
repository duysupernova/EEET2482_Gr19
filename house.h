#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "Member.h"             
#include "Period.h"
#include "Request.h"
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

class House{
private:
    string location;
    string description;
    string city;
    double house_Rating;   
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
    void getCity();//(fix)
    void getLocation();//(fix)
    void getDescription();//(fix)
    void getUserReview();//(fix)
    void houseRating();//(fix)
    void addRequest(Request requestToAdd);
    void addReview(Member &member, string reviewString);
    void checkIfQualify(Member member);
    void listHouse(Member member);
    void unlistHouse(); 
    friend void saveToFile(string fileName, vector<House> &houseArr, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect,vector<House> &houseVect, char fDelimit);
};

#endif
