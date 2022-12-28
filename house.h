#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "request.h"
#include <vector>
using std::vector;

class House{
private:
    string location;
    string description;
    string city;
    int house_Rating;   
    Period periodForOccupy;

    vector<string> userReviews;
    vector<Request> requestsToOccupy;

public:
    House(string locationVal="", string descriptVal="", string cityVal="", int hRating=0, 
            Period period = Period(0,0,0,0,0,0), vector<string> reviews={}, vector<Request> requests={}); 
    void addRequest(Request requestToAdd);
    friend class FileHandling;
};



#endif