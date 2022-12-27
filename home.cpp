#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::cin;
using std::cout;

class HOUSE{
private:
//For user review the house
    string User_review;
    int House_Rating = 0;
    int avgHouse_Rating = 0; 
    int Total_HouseRating = 0; //sum of all user rating score
    int number_of_user; //total  user

//some basic infomation of the house
    string name;
    string location;
    string description;



    //std::vector<*Member> request;
    std::vector<string> review; 

//For Owner review Occupier
    int Score_For_Renter;
    string Owner_Review;
    int Owners;  //Total of Owners
    int Total_of_ownerscore;
    int avgScore_For_Renter;


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
//đoạn này em ko bik cách thu thập user review bằng vector
    //get user review
    // string GetUser_review(){
    //     cout<< "Please give review about the house: ";
    //     getline(cin, User_review);
    //     return User_review;
    // }


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
        int avgHouse_Rating = Total_HouseRating / number_of_user; //get average rating score

        return avgHouse_Rating;
    }

//Owners review for a Renter(how well that occupier has taken care of the house)
    //đoạn này tương tụ
//     string GetRenter_review(){
//         cout<< "Please give review about the renter: ";
//         getline(cin, Owner_Review);
//         return Owner_Review;
//     }

//Owners will rate a renter(how well that occupier has taken care of the house)
    float GetUser_Rating(){ 
        cout << "Please rate quality of the User from -10(Very Dislikke) - 10(Very like): ";
        cin >> Score_For_Renter;

        while (Score_For_Renter> 10 || Score_For_Renter < -10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the User from -10(Very Dislike) - 10(Very like): ";
            cin >> Score_For_Renter;
        }
        return Score_For_Renter;

    }

//averaging the ratings of all house owners who had let their houses to be used by that occupier how well that occupier has taken care of the house. 
    float occupier_rating_score(){
        Total_of_ownerscore += Score_For_Renter; //Get Total of user rating score
        int avgScore_For_Renter = Total_of_ownerscore / Owners; //need to find a way to collect Owners value

        return avgScore_For_Renter;
    }
    

    void showHouseInfo1(){ //show info that guest can see
        std::cout << "Name = " << name
                  << ", location = " << location
                  << "\ndescription = "<< description
                  << "\nScore required = " << avgHouse_Rating;
    }

    void showHouseInfo2(){ //show more info for member and admin
        std::cout << "Name = " << name
                  << ", location = " << location
                  << "\ndescription = "<< description
                  <<"\nUser review = " << User_review
                  <<"\nHouse Rating = " << avgHouse_Rating;
                  
    }

    HOUSE(){} //Default constructor


};
int main(){
    HOUSE house1;
    house1.Getname();
    house1.Getlocation();
    house1.Getdescription();

   // house1.GetUser_review();
    house1.GetHouse_Rating();


    house1.showHouseInfo2(); //for member and admin





    return 0;
}
