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
    Member *owner;
    string location;
    string description;
    string city;
    int house_Rating;   
    Period periodForOccupy;
    

    vector<string> userReviews;
    vector<Request> requestsToOccupy;

public:
    House(string locationVal="", string descriptVal="", string cityVal="", int hRating=0, 
            Period period = Period(0,0,0,0,0,0), vector<string> reviews={}, vector<Request> requests={},Member *owner = nullptr); 
    void showHouseInfo2();
    
    void addRequest(Request requestToAdd);

    friend void saveToFile(string fileName, vector<Member> &memberArr);
};



#endif