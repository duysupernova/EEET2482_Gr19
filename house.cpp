#include "House.h"
#include "member.h"

House::House(Member* ownerVal,string locationVal, string descriptVal, string cityVal, double hRating, int numRatings, int minOccupierVal, int ptVal, Period period, vector<string> reviews, vector<Request> requests):
            location(locationVal),description(descriptVal),city(cityVal), house_Rating(hRating), numOfRatings(numRatings), minOccupierRating(minOccupierVal), ptPerDay(ptVal),
            periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){
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





void House::checkIfQualify(Member member){
    if(ptPerDay < member.getCreditPoint()) {
        cout << "You dont have enough point to rent this house!";
    } 
    if (ptPerDay < member.getOccupierScore()) {
        cout << "You dont have enough point to rent this house!";
    }
    else {
        cout << "You have successfully rent this house!";
    }
}

void House::listHouse(Member member){
    int sDate, sMonth, sYear, eDate, eMonth, eYear;
    cout << "Please enter start day: ";
    cin >> sDate;
    cout << "Please enter month: ";
    cin >> sMonth;
    cout << "Please enter year: ";
    cin >> sYear;
    cout << "Please enter end day: ";
    cin >> eDate;
    cout << "Please enter month: ";
    cin >> eMonth;
    cout << "Please enter year: ";
    cin  >> eYear;
    periodForOccupy = Period(sDate, sMonth, sYear, eDate, eMonth, eYear);
    cout << "Please enter a consuming point per day: ";
    cin >> ptPerDay;
    cout << "Please enter a minimum required occupier rating: ";
    cin >> minOccupierRating;
    checkIfQualify(member);
}

void House::unlistHouse(){ 
    periodForOccupy = Period(1,1,1,2,1,1);
    cout << "Successful unlist house!";
}



// int main(){
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
//     House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

//     return 0;
// }