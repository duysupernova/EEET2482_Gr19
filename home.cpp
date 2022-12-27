#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::cin;
using std::cout;

class HOUSE{
private:
    string User_review;
    int House_Rating = 0;
    int avgHouse_Rating = 0;
    int Total_HouseRating = 0;
    string name;
    string location;
    string description;

    int Score_required;
    int number_of_user;
    //std::vector<*Member> request;
    std::vector<string> review; 

public:
    string Getname(){
        cout << "Enter house name: ";
        getline(cin, name);
        return name;
    }

    //input description for the house
    string Getdescription(){
        cout << "Input description about the house: ";
        getline(cin, description);

        return description;
    }

    //select city
    string Getlocation(){
        cout << "Enter house location: ";
        getline(cin, location);
        if ((location != "Ha Noi") && (location != "Hue") && (location != "Sai Gon")){ //limit the city choice
            cout << "Wrong input city (Ha Noi, Hue, Sai Gon), Please choose a city: ";
            getline(cin, location);
        };
        return location;
    }

    //get user review
    string GetUser_review(){
        cout<< "Please give review about the house: ";
        getline(cin, User_review);
        return User_review;
    }

    //ask user to rate the house from -10 to 10
    float GetHouse_Rating(){ 
        cout << "Please rate quality of the house from -10(Very Dislikke) - 10(Very like): ";
        cin >> House_Rating;

        while (House_Rating > 10 || House_Rating < -10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the house from -10(Very Dislike) - 10(Very like): ";
            cin >> House_Rating;
        }
        return House_Rating;

    }


        //calculate the house rating score
    float User_review_House_Rating(){
        Total_HouseRating += House_Rating; //Get Total of house rating score
        int avgHouse_Rating = Total_HouseRating / number_of_user; //need to get number of user somewhere...

        return avgHouse_Rating;
    }

    void showHouseInfo1(){ //show info that guest can see
        std::cout << "Name = " << name
                  << ", location = " << location
                  << "\ndescription = "<< description
                  << "\ncity = " << location
                  << "\nScore required = " << avgHouse_Rating;
    }

    void showHouseInfo2(){ //show more info for member and admin
        std::cout << "Name = " << name
                  << ", location = " << location
                  << "\ndescription = "<< description
                  <<"\nUser review = " << User_review
                  <<"\nHouse Rating = " << avgHouse_Rating;
                  


    }
    HOUSE(){}



};
int main(){
    HOUSE house1;
    house1.Getname();
    house1.Getlocation();
    house1.Getdescription();

    house1.GetUser_review();
    house1.GetHouse_Rating();

    house1.showHouseInfo2(); //for member and admin





    return 0;
}
