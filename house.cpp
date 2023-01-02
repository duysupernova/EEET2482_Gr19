#include "House.h"



House::House(string locationVal, string descriptVal, string cityVal, double hRating, int numRatings, Period period, vector<string> reviews, vector<Request> requests,Member* ownerVal):
            location(locationVal),description(descriptVal),city(cityVal), house_Rating(hRating), numOfRatings(numRatings),periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){
                this->owner = ownerVal;
            };

Member *House::getOwner(){
    return owner;
};
void House::setOwner(Member* member){
    this->owner = member;
}


void House::showHouseInfo(){ //show more info for member and admin
    cout << endl << "HOUSE location = " << location << endl;
    cout << "Description = "<< description << endl;
    cout << "City = " << city << endl;
    cout << "User review(s) = " << endl; //test print out the vector string
    for (string review : userReviews){
        cout << "\t" << review << "\n";
    }
    cout << "Requests = "<< endl; //test print out the vector string
    for (Request request : requestsToOccupy){
        cout << "\t" << request.toString() << "\n";
    }
    cout << "House Rating = " << house_Rating << endl;
                
}

void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}
void House::addReview(Member &member, string reviewString){
    userReviews.push_back(member.userName + ": " + reviewString);
}






// int main(){
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
//     House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

//     return 0;
// }