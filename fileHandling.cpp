#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "period.h"
using std::vector;
using std::string;



class House{
private:
    string location;
    string description;
    string city;
    int house_Rating;   
    Period periodForOccupy;

    vector<string> userReviews;
    vector<Request> requestsToOccupy;

public:
    House(string locationVal="", string descriptVal="", string cityVal="", int hRating=0, Period period = Period(0,0,0,0,0,0), vector<string> reviews={}, vector<Request> requests={}):
    location(locationVal),description(descriptVal),city(cityVal), house_Rating(hRating), periodForOccupy(period),userReviews(reviews),requestsToOccupy(requests){};
    
    void addRequest(Request requestToAdd){
        requestsToOccupy.push_back(requestToAdd);
    }
    friend class FileHandling;
};

class Guest{
    private:
    string guestFullName;
    string guestUserName;
    string guestPassword;
    int guestPhone;
    public:
    Guest(string guestFullName = " ", string guestUserName = " ", string guestPassword = " ", int guestPhoneVal = 0) : guestFullName(guestFullName), guestUserName(guestUserName), 
                                                                                                guestPassword(guestPassword), guestPhone(guestPhoneVal){}
    void register_form();
    void display_house();
};

class Member : public Guest{
private:
    string fullName;
    string userName;
    string password;
    int phoneNumber;
    int creditPoint;
    int occupierRatingScore;
    House houseForRent;
public:
    // Constructor for object member
    Member(string fullName = " ", string userName = " ", string password = " ",  int phone = 0, int creditPointVal = 500, int occupierRatingScoreVal = 0) 
    : Guest(fullName, userName, password, phone),creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal), houseForRent(House()){};
    string &getUserName() {
        return userName;
    }
    void addHouse (House &house){
        this->houseForRent = house;
    }
    void requestToOccupy(House &house,int sd,int sm,int sy,int ed, int em,int ey){
        house.addRequest(Request(*this,Period(sd,sm,sy,ed,em,ey)));
    };
    void login_form();
    friend class FileHandling;
};

class Request {
    Member &memberWantToOccupy;
    Period periodToOccupy;
public:
    Request (Member &memberVal, Period period):
    memberWantToOccupy(memberVal),periodToOccupy(period){};

    string toString() {
        return memberWantToOccupy.getUserName() + "&&" + periodToOccupy.toString();
    }
};


class FileHandling {
public:
    void saveToFile(string fileName, vector<Member> &memberArr) {
        std::fstream myfile;
        myfile.open(fileName,std::ios::out);
        for (Member member : memberArr){
            myfile << member.fullName << ",";
            myfile << member.userName << ",";
            myfile << member.password << ",";
            myfile << member.phoneNumber << ",";
            myfile << member.creditPoint << ",";
            myfile << member.occupierRatingScore << ",";
            // House time
            myfile << member.houseForRent.location<<",";
            myfile << member.houseForRent.description<<",";
            myfile << member.houseForRent.house_Rating<<",";
            myfile << member.houseForRent.city<<",";
            myfile << member.houseForRent.periodForOccupy.toString() << ",";
            for (string review : member.houseForRent.userReviews){
                myfile << review << "|||";
            }
            myfile << ",";
            for (Request request : member.houseForRent.requestsToOccupy){
                myfile << request.toString() << "|||";
            }
            myfile << "\n";
        }
    }
};

int main() {
    FileHandling filehandler;
    vector<Member> memberArr ;
    House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"});
    Member m1("Nguyen Huu Khang","metalbox","09122003",12344442);
    m1.addHouse(h1);

    memberArr.push_back(m1);

    filehandler.saveToFile("database.csv",memberArr);

    // Test save data
}