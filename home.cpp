#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

class HOUSE{
private:

    string house_name;
    string location;
    string description;
    string city;
    int Score_required;

    string User_review;
    int House_Rating;    
public:


    // Chinh lai phan class house nhe, may cai attribute thi em phai de private het
    // Con phan public chi de function ra thoi vd: void display() gi do

    //cal avg rating
    int averageRating(int usertotal){
        int Avg = House_Rating / usertotal;

        return Avg;
    }
    
    //get house décription
    void Getdescription(){
        cout << "Input desciption about the house: \n";
        getline(cin, description);
        return ;
    }

    string GetcityLive(){
        getline(cin, city);
        if ((city != "Ha Noi") || (city != "Hue") || (city != "Sai Gon")){
            cout << "Wrong input city (Ha Noi, Hue, Sai Gon), Please choose a city: ";
            getline(cin, city);
        };
        return city;
    }
    
//     string GetUser_review(){
//         getline(cin, User_review);
//         return User_review;
//     }

    void showHouseInfo(){
        std::cout << "Name = " << name
                  << ", location = " << location
                  << "\ndescription = "<< description
                  << "\ncity = " << city
                  << "\nScore required = " << Score_required;
    }

    void showHouseInfo2(){
        std::cout <<"User review = " << User_review
                  <<"House Rating = " << House_Rating;


    }

};
int main(){
    HOUSE house1;

    house1.Getdescription();
    house1.GetcityLive();

    house1.showHouseInfo();





    return 0;
}
