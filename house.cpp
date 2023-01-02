#include "House.h"
#include "member.h"

House::House(string locationVal, string descriptVal, string cityVal, int hRating, Period period, vector<string> reviews, vector<Request> requests,Member *ownerVal):
            owner(ownerVal),location(locationVal),description(descriptVal),city(cityVal), houseRating(hRating), periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){};

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
    cout << "House Rating = " << houseRating << endl;
                
}
void House::getLocation(){
        cout <<"Enter house location: ";
        getline(cin,location);

        while(location == ""){ //error check
            cout <<"You must not leave location empty, please enter house location: ";
            getline(cin,location);
        }
    }//(fix)
void House::getCity(){
    cout << "Enter city(Ha Noi, Hue, Sai Gon): ";
    getline(cin, city);
    while ((city != "Ha Noi") && (city != "Hue") && (city != "Sai Gon") && (city == "")){ //limit the city choice
         cout << "Wrong input city (Ha Noi, Hue, Sai Gon), Please choose a city: ";
         getline(cin, city);
         }
    }//(fix)

void House::getDescription(){
    cout << "Input description about the house: ";
    getline(cin, description);
    while(description ==""){
        cout << "The description is empty, please enter description about the house: ";
        getline(cin, description);
    }
}//(fix)

void House::getUserReview(){
        string userReview;
        cout <<"What are your comment about the house: ";
        getline(cin, userReview);
        userReviews.push_back (userReview);
    } //(fix)

void House::getHouseRating(int temp){
        cout << "Please rate quality of the house from -10(Very Dislikke) to 10(Very like): ";
        cin >> temp;
        while (temp < -10 || temp > 10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the quality of house from -10(Very Dislike) to 10(Very like): ";
            cin >> temp;
    
        }
        houseRating = ((houseRating * requestsToOccupy.size())+ temp)/ (requestsToOccupy.size() +1);
    }//(fix)

void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}

void House::checkIfQualify(Member member){
    if(consumingPointPerDay < member.getCreditPoint()) {
        cout << "You dont have enough point to rent this house!";
    } 
    if (minimumOcupierRating < member.getOccupierScore()) {
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
    cin >> consumingPointPerDay;
    cout << "Please enter a minimum required occupier rating: ";
    cin >> minimumOcupierRating;
    checkIfQualify(member);
}

void House::unlistHouse(){ 
    periodForOccupy = Period(1,1,1,2,1,1);
    cout << "Successful unlist house!";
}



int main(){
    Member m1("Nguyen Huu Khang","metalbox","password",12344442);
    m1.showInfo();
    House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

    return 0;
}
