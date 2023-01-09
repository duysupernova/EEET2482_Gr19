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

Period &House::getPeriodForOccupy(){
    return this->periodForOccupy;
};
void House::setOwner(Member* member){
    this->owner = member;
}

void House::showHouseInfo(){ //show more info for member and admin
    cout << endl << "HOUSE location = " << location << endl;
    cout << "Description = "<< description << endl;
    cout << "City = " << city << endl;
    cout << "Period for rent: "; periodForOccupy.showInfo();
    cout << "Points per day: " << ptPerDay;
    cout << "Minimun rating required: " << minOccupierRating;
    cout << "House Rating = " << houseRating << endl;                
    cout << "User review(s) = " << endl; //test print out the vector string
    for (string review : userReviews){
        cout << "\t" << review << "\n";
    }
    cout << "Requests = "<< endl; //test print out the vector string
    for (Request request : requestsToOccupy){
        cout << "\t" << request.toString() << "\n";
    }
}
void House::showInfoFull(){
    string tempt;
    this->owner->showInfo();
    showHouseInfo();
    cout << "\n\nPress a character and enter to continue\n";
    cin >> tempt;
}
void House::showInfoMini(){
    cout << endl << "HOUSE location = " << location << endl;
    cout << "Description = "<< description << endl;
    cout << "City = " << city << endl;
}


void House::addRequest(Request requestToAdd){
    requestsToOccupy.push_back(requestToAdd);
}
void House::addReview(Member *member, string reviewString){
    userReviews.push_back(member->userName + ": " + reviewString);
}

void House::registerHouseMenu(){ //for member add house
    string tempt;
    system("cls");
    cout << "*====HOUSE INFO====*\n\n";

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

    cout << "\n\nInformation updated successfully!\n";
    cout << "Press any character and enter to continue\n";
    cin >> tempt;
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
    string tempt;
    int sDate, sMonth, sYear, eDate, eMonth, eYear;
    system("cls");
    cout << "*====LIST HOUSE====*\n";

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
        
    cout << "\nList house from " ; periodForOccupy.showInfo(); 
    cout << "With price " << ptPerDay << " per day for renters rating above " << minOccupierRating;

    cout << "\n\nPress any character and enter to continue\n";
    cin >> tempt;
}

void House::unlistHouse(){ 
    string tempt;
    periodForOccupy = Period(1,1,1970,2,1,1970);
    system("cls");
    cout << "*====UNLIST HOUSE====*\n";

    cout << "\nSuccessful unlist house!\n";
    cout << "Press any character and enter to continue\n";
    cin >> tempt;
}

void House::viewRequest(){
    for (int i = 0; i < requestsToOccupy.size();i++){
        cout << i+1 <<". " << requestsToOccupy[i].getMemberToOccupy() << ": " << requestsToOccupy[i].getPeriod().toString() << endl;
    }
}


void House::acceptRequest(){
    string temp;
    int indexOfAccptReq;
    vector<Request*> pendingRequests = {};            
    vector<int> indexOfReqDel = {};

    system("cls");
    
    cout << "*====PENDING REQUESTS====*\n";
    // Filter out and print the unaccepted requests
    for (int i = 0; i < requestsToOccupy.size(); i++){
        if(!requestsToOccupy[i].getIsAccept()){
            pendingRequests.push_back(&requestsToOccupy[i]);
            cout << i+1 <<". " << requestsToOccupy[i].getMemberToOccupy() << ": " << requestsToOccupy[i].getPeriod().toString() << endl;
        }
    }
    cout << "Please enter a number to accept a request\n ";
    cout << "Or a random NUMBER to exit\n";
    cin >> indexOfAccptReq;
    indexOfAccptReq -= 1;
    if(indexOfAccptReq >= pendingRequests.size() || indexOfAccptReq < 0){
        return;
    } else {
        pendingRequests[indexOfAccptReq]->setIsAccept(true);
        // Find requests that are overlapping
        for (int i = 0; i < requestsToOccupy.size(); i++) {
            if(requestsToOccupy[i].getIsAccept()){
                continue;
            }
            if(pendingRequests[indexOfAccptReq]->getPeriod().isOverlapPeriod(requestsToOccupy[i].getPeriod())) {
                indexOfReqDel.push_back(i);
            }
        }
        // Finally delete the requests
        for (int i = indexOfReqDel.size() - 1; i >= 0; i--) {
            requestsToOccupy.erase(requestsToOccupy.begin()+indexOfReqDel[i]);
            cout << "A overlapped request deleted!\n";
        }
        cout << "\n\nRequest Accepted successfully\n";
        cout << "Press any character and enter to continue\n";
        cin >> temp;

    }
}

void House::sreachHouse(vector<House> &houseVec){
    string temp;
    int sDate, sMonth, sYear, eDate, eMonth, eYear;
    int indexOfReqHouse;
    int indexOfAvailHouse = 0;
    vector<House*> availHouses = {};

    system("cls");
    cout << "**Please enter the period you want to occupy at this house**\n\n";
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
    
    system("cls");
    cout << "\n\n*====Available houses====*\n";
    cout << "From ";periodForSreachHouse.showInfo();
    for (int i = 0; i < houseVec.size(); i++){
        if(houseVec[i].city != this->city){
            continue;
        }
        if(houseVec[i].periodForOccupy.isInsidePeriod(periodForSreachHouse)){
            cout << "[" << indexOfAvailHouse+1 << "]\n";
            houseVec[i].showHouseInfo();
            availHouses.push_back(&houseVec[i]);
            indexOfAvailHouse += 1;
        }
    }
    // Ask if user want to only view or actually book a request
    cout << "\n\nPress the number of house you want to occupy OR a random NUMBER to exit\n";
    cin >> indexOfReqHouse;
    indexOfReqHouse--;
    if (indexOfReqHouse < availHouses.size() && indexOfReqHouse >= 0){
        availHouses[indexOfReqHouse]->addRequest(Request(this->owner->getUserName(),periodForSreachHouse,false));
        cout << "\n\nRequest Added successfully";
        cout << "\nPress any character and enter to continue\n";
        cin >> temp;
        return;
    }
}


void House::rateOccupier(vector<House> &houseVec){
    int temptIndex;
    string temptStr;
    vector<Request> acceptedRequests = {};
    // To find the past occupiers
    for (int i = 0; i < requestsToOccupy.size(); i++ ){
        if(requestsToOccupy[i].getIsAccept()){
            acceptedRequests.push_back(requestsToOccupy[i]);
        }
    }

    system("cls");
    // Print out the accepted requests 
    for (int i = 0; i < acceptedRequests.size();i++){
        cout << i+1 <<". " << acceptedRequests[i].getMemberToOccupy() << ": " << acceptedRequests[i].getPeriod().toString() << endl;
    }
    // Choosing the person to rate
    cout << "Please choose a number to rate that occupier: ";
    cin >> temptIndex; 
    temptIndex -= 1;
    // Actually go
    if(temptIndex >= acceptedRequests.size()){    // To advoid out of bounds
        cout << "\n\nInvalid input!\n";
        cout << "Press any character and enter to continue \n";
        cin >> temptStr;
    } else {
        for (House house : houseVec){
            if(house.owner->getUserName() == acceptedRequests[temptIndex].getMemberToOccupy()){
                house.owner->calOcuNewScore();
                break;
            }
        }
        cout << "\n\nRated sucessfully!\n";
        cout << "Press any character and enter to continue\n";
        cin >> temptStr;
    }
}

void House::viewRequestsMade(vector<House> &houseVec){
    string temptStr;
    vector<Request*> requestsMade = {};
    vector<Request*> requestsMadeAccepted = {};
    vector<string> requestHLoca = {};
    vector<string> accptRequestHLoca = {};

    // Find all the requests made by this user and filter them into distinct vectors
    int houseVecSize = houseVec.size();
    int requestVecSize;

    for (int i = 0; i < houseVecSize; i++){
        requestVecSize = houseVec[i].requestsToOccupy.size();
        for(int j = 0; j < requestVecSize; j++){
            Request& reqTempt = houseVec[i].requestsToOccupy[j];
            if (reqTempt.getMemberToOccupy() == this->owner->userName){
                if(reqTempt.getIsAccept()){          
                    requestsMadeAccepted.push_back(&reqTempt);
                    accptRequestHLoca.push_back(houseVec[i].location);
                } else {
                    requestsMade.push_back(&reqTempt);
                    requestHLoca.push_back(houseVec[i].location);
                }
            }
        }
    }
    // Print out all the request made by this user
    system("cls");
    cout << "All pending requests:" << endl;
    for(int i = 0; i < requestsMade.size(); i++){
        cout << "[" << i+1 << "] At " << requestHLoca[i] << endl;
        requestsMadeAccepted[i]->showInfo(); 
        cout << endl;    
    }
    cout << "\nAccepted requests:" << endl;
    for(int i = 0; i < requestsMadeAccepted.size(); i++){
        cout << "[" << i+1 << "] At " << accptRequestHLoca[i] << endl;
        requestsMadeAccepted[i]->showInfo(); 
        cout << endl;    
    }
    cout << "\n\nPress any character and enter to return\n";
    cin >> temptStr;
}





// int main(){
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
//     House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

//     return 0;
// }