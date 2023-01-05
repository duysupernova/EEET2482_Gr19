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

class House{
private:
    string location;
    string description;
    string city;
    double house_Rating;   
    int numOfRatings;
    int minOccupierRating;
    Period periodForOccupy;

    vector<string> userReviews;
    vector<Request> requestsToOccupy;
    Member* owner;

public:
    House(Member* owner = nullptr,string locationVal="", string descriptVal="", string cityVal="", double hRating=0, int numRating=0,int minOccupierVal = 0,
            Period period = Period(1,1,1,1,1,1), vector<string> reviews={}, vector<Request> requests={}); 
    Member *getOwner();
    void setOwner(Member* member);
    void showHouseInfo();
    
    void addRequest(Request requestToAdd);
    void addReview(Member &member, string reviewString);
    friend void saveToFile(string fileName, vector<House> &houseArr, char firstDelimiter, char secDelimiter);
    friend void loadFromFile(string fileName,vector<Member> &memberVect, vector<Request> &requestVect,  vector<House> &houseVect, char fDelimit, char sDelimit);

};

#endif