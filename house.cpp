#include "House.h"
#include "member.h"

House::House(Member* ownerVal,string locationVal, string descriptVal, string cityVal, double hRating, int numRatings, int minOccupierVal, int ptVal, Period period, vector<string> reviews, vector<Request> requests):
            location(locationVal),description(descriptVal),city(cityVal), houseRating(hRating), numOfRatings(numRatings), minOccupierRating(minOccupierVal), ptPerDay(ptVal),
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
    cout << "House Rating = " << houseRating << endl;
                
}

void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}
void House::addReview(Member *member, string reviewString){
    userReviews.push_back(member->userName + ": " + reviewString);
}

void House::registerHouseMenu(){ //for member add house
    cout <<"Enter house location: ";
    cin.ignore(1,'\n');
    getline(cin,location);

    while(location == ""){ //error check
        cout <<"You must not leave location empty! Please please re-enter location: ";
        getline(cin,location);
    }
    cout << "Enter city(Ha Noi, Hue, Sai Gon): ";
    getline(cin, city);
    while ((city != "Ha Noi") && (city != "Hue") && (city != "Sai Gon")){ //limit the city choice
        cout << "Wrong input city, Please choose a city(Ha Noi, Hue, Sai Gon): ";
        getline(cin, city);
        }
    cout << "Input description about the house: ";
    getline(cin, description);
    while(description ==""){
        cout << "The description is empty, please enter description about the house: ";
        getline(cin, description);
    }
}

void House::getUserReview(){//occupier input review about the house
        string userReview;
        cout <<"What are your comment about the house: ";
        getline(cin, userReview);
        userReviews.push_back (userReview);
    } //(fix)

void House::getHouseRating(int temp){//occupier rate the score of the house
        cout << "Please rate quality of the house from -10(Very Dislikke) to 10(Very like): ";
        cin >> temp;
        while (temp < -10 || temp > 10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the quality of house from -10(Very Dislike) to 10(Very like): ";
            cin >> temp;
    
        }
        houseRating = ((houseRating * requestsToOccupy.size())+ temp)/ (requestsToOccupy.size() +1);
    }//(fix)






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

void House::listHouse(){
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
}

void House::unlistHouse(){ 
    periodForOccupy = Period(1,1,1,2,1,1);
    cout << "Successful unlist house!";
}

void House::viewRequest(){
    for (int i = 0; i < requestsToOccupy.size();i++){
        cout << i+1 <<". " << requestsToOccupy[i].getMemberToOccupy() << ": " << requestsToOccupy[i].getPeriod().toString() << endl;

    }
}


void House::acceptRequest(){
    system("cls");
    viewRequest();
    int temp;
    cout << "Please enter a number to accept a request: ";
    cin >> temp;
    if(temp-1 >= requestsToOccupy.size()){
        cout << "Invalid input!";
    } else {
        requestsToOccupy[temp-1].setIsAccept(true);
        vector<int> indexOfReqDel = {};
        // Find requests that are overlapping
        for (int i = 0; i < requestsToOccupy.size(); i++) {
            if(i == temp-1){
                continue;
            }
            if(requestsToOccupy[temp-1].getPeriod().isOverlapPeriod(requestsToOccupy[i].getPeriod())) {
                indexOfReqDel.push_back(temp-1);
            }
        }
        // Finally delete the requests
        for (int i = indexOfReqDel.size() - 1; i >= 0; i--) {
            requestsToOccupy.erase(requestsToOccupy.begin()+indexOfReqDel[i]);
        }
        cout << "Request Accepted successfully\n";
        cout << "Press any number to continue";
        cin >> temp;

    }
}

void House::sreachHouse(vector<House> &houseVec){
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
    cin >> eYear;
    Period periodForSreachHouse = Period(sDate, sMonth, sYear, eDate, eMonth, eYear);

    for (int i = 0; i << houseVec.size(); i++){
        if(houseVec[i].periodForOccupy.isInsidePeriod(periodForSreachHouse)){
            houseVec[i].showHouseInfo();
        }
    }
}

void House::rateOccupier(vector<House> &houseVec){
    int temptIndex;
    string temptReview;
    vector<Request> acceptedRequests = {};
    // To find finshed occupier
    for (int i = 0; i < requestsToOccupy.size(); i++ ){
        if(requestsToOccupy[i].getIsAccept()){
            acceptedRequests.push_back(requestsToOccupy[i]);
        }
    }
    // To list the occupiers

    // Print out the accepted requests 
    for (int i = 0; i < acceptedRequests.size();i++){
        cout << i+1 <<". " << acceptedRequests[i].getMemberToOccupy() << ": " << acceptedRequests[i].getPeriod().toString() << endl;
    }
    // Choosing the person to rate
    cout << "Please choose a number to rate that occupier: ";
    cin >> temptIndex; 
    // Actually go
    if(temptIndex-1 >= acceptedRequests.size()){    // To advoid out of bounds
        cout << "Invalid input!";
    } else {
        for (House house : houseVec){
            if(house.owner->getUserName() == acceptedRequests[temptIndex].getMemberToOccupy()){
                house.owner->calOcuNewScore();
                cout << "Add review sucessfully!\n";
                break;
            }
        }
        cout << "Press any number to continue";
        cin >> temptIndex;

    }

}

// int main(){
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
//     House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

//     return 0;
// }