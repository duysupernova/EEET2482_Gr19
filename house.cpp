#include "house.h"

House::House(string locationVal="", string descriptVal="", string cityVal="", int hRating=0, Period period = Period(0,0,0,0,0,0), vector<string> reviews={}, vector<Request> requests={}):
location(locationVal),description(descriptVal),city(cityVal), house_Rating(hRating), periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){};

void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}