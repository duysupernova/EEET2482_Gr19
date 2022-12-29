#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class House{
private:
//some basic infomation of the house
    string location;
    string description;
//For user review the house
    int House_Rating = 0;
    int number_of_user = 0; //total  user

    //std::vector<*Member> request;
    std::vector<string> review; 

// //For Owner review Occupier
//     int Score_For_Renter;
//     vector<string> review_Owner;
//     int Owners;  //Total of Owners
//     int Total_of_ownerscore;
//     int avgScore_For_Renter;


public:
    //select city
    string get_Location(){
        cout << "Enter house location(Ha Noi, Hue, Sai Gon): ";
        getline(cin, location);
        while ((location != "Ha Noi") && (location != "Hue") && (location != "Sai Gon")){ //limit the city choice
            cout << "Wrong input city (Ha Noi, Hue, Sai Gon), Please choose a city: ";
            getline(cin, location);
        }
        return location;
    }

    //input description for the house
   string get_Description(){
        cout << "Input description about the house: ";
        getline(cin, description);
        return description;
    }

    //for everytime Rentors rent succesfully the same house
    void Success(){
        cout << "Congrat, you have successfully rented this house"; << endl;
        number_of_user++;       
    }



    //get user review
    void get_User_review(){
        string User_review;
        cout <<"What are your thought about the house: ";
        getline(cin, User_review);
        review.push_back (User_review);
    }


    //ask user to rate the house from -10 to 10
   void get_House_Rating(){ 
        cout << "Please rate quality of the house from -10(Very Dislikke) - 10(Very like): ";
        cin >> House_Rating;

        while (House_Rating < -10 || House_Rating > 10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the house from -10(Very Dislike) - 10(Very like): ";
            cin >> House_Rating;
        }

    }


        //calculate the house rating score
    int User_review_House_Rating(){
        int avgHouse_Rating = 0;
        int Total_HouseRating = 0; //sum of all user rating score
        
        Total_HouseRating += House_Rating; //Get Total of house rating score
        avgHouse_Rating = Total_HouseRating / number_of_user; //get average rating score
        return avgHouse_Rating;
    }

    void showHouseInfo1(){ //show info that guest can see(Dont have User review)
        std::cout << "location = " << location << endl
                  << "description = "<< description << endl
                  << "Score required = " << User_review_House_Rating() << endl;
    }

    void showHouseInfo2(){ //show more info for member and admin
        std::cout << "location = " << location << endl
                  << "description = "<< description << endl
                  <<"User review = " <<  review[0]<< endl //test print out the vector string
                  <<"House Rating = " << User_review_House_Rating() << endl;
                  
    }

    House(){} //Default constructor


};
int main(){
    House house1;
    house1.get_Location();
    house1.get_Description();
    house1.Success();
    house1.Success();
    house1.get_User_review();
    house1.get_House_Rating();

    house1.showHouseInfo1(); //for guest
    cout << "\n";
    house1.showHouseInfo2(); //for member and admin





    return 0;
}
