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
    Member *owner;
    string location;
    string description;
    string city;
    int house_Rating;   
    Period periodForOccupy;
    int consumingPointPerDay;
    double minimumOcupierRating;
    vector<string> userReviews;
    vector<Request> requestsToOccupy;

public:
    House(string locationVal="", string descriptVal="", string cityVal="", int hRating=0, 
            Period period = Period(0,0,0,0,0,0), vector<string> reviews={}, vector<Request> requests={},Member *owner = nullptr); 
    void showHouseInfo();
    void getCity();//(fix)
    void getLocation();//(fix)
    void getDescription();//(fix)
    void getUserReview();//(fix)
    void houseRating();//(fix)
    void addRequest(Request requestToAdd);
    void checkIfQualify(Member member);
    void listHouse(Member member);
    void unlistHouse(); 
    friend void saveToFile(string fileName, vector<House> &houseArr, string firstDelimiter, string secDelimiter);
};

#endif
