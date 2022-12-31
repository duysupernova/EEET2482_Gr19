#include "House.h"



House::House(string locationVal, string descriptVal, string cityVal, int hRating, Period period, vector<string> reviews, vector<Request> requests,Member *ownerVal):
            owner(ownerVal),location(locationVal),description(descriptVal),city(cityVal), house_Rating(hRating), periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){};

void House::showHouseInfo(){ //show more info for member and admin
    cout << "HOUSE location = " << location << endl;
    cout << "Description = "<< description << endl;
    cout << "City = " << city << endl;
    cout << "User review = " << endl; //test print out the vector string
    for (string review : userReviews){
        cout << "\t" << review;
    }
    cout << endl << "Requests = "<< endl; //test print out the vector string
    for (Request request : requestsToOccupy){
        cout << "\t" << request.toString();
    }
    cout << "House Rating = " << house_Rating << endl;
                
}

void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}


// int main(){
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
//     House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

//     return 0;
// }