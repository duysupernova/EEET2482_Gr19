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
    cout << "House Rating = " << getHouseRating() << endl;
                
}

string getLocation(){
        cout <<"Enter house location: ";
        getline(cin,location);

        while(location == ""){ //error check
            cout <<"You must not leave location empty, please enter house location: ";
            getline(cin,location);
        }
            return location;
    }


string getCity(){
    cout << "Enter city(Ha Noi, Hue, Sai Gon): ";
    getline(cin, city);
    while ((city != "Ha Noi") && (city != "Hue") && (city != "Sai Gon") && (city == "")){ //limit the city choice
         cout << "Wrong input city (Ha Noi, Hue, Sai Gon), Please choose a city: ";
         getline(cin, city);
         }
            return city;
    }//(fix)

    string getDescription(){
        cout << "Input description about the house: ";
        getline(cin, description);
        while(description ==""){           
           cout << "the description is empty, please enter description about the house: ";
           getline(cin, description);       
        }
            return description;
    }//(fix)

    void getUserReview(){
        string userReview;
        cout <<"What are your comment about the house: ";
        getline(cin, userReview);
        userReviews.push_back (userReview);
    } //(fix)

    double getHouseRating(){
        cout << "Please rate quality of the house from -10(Very Dislikke) to 10(Very like): ";
        cin >> houseRating;
        while (houseRating < -10 || houseRating > 10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the quality of house from -10(Very Dislike) to 10(Very like): ";
            cin >> houseRating;
        }
        totalHouseRating += houseRating;
        double avgHouseRating =  totalHouseRating / requestsToOccupy().size;
        return avgHouseRating;
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
