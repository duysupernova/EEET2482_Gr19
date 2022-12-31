// Your First C++ Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "period.h"
#include "house.h"
#include "member.h"
#include "request.h"


void saveToFile(string fileName, vector<House> &houseVec, string firstDelimiter, string secDelimiter) {
    std::fstream myfile;
    myfile.open(fileName,std::ios::out);
    for (House house : houseVec){
        myfile << house.owner->fullName << firstDelimiter;         // VSCode says it's inacessible
        myfile << house.owner->userName << firstDelimiter;         // But it is acessible
        myfile << house.owner->password << firstDelimiter;
        myfile << house.owner->phoneNumber << firstDelimiter;
        myfile << house.owner->creditPoint << firstDelimiter;
        myfile << house.owner->occupierRatingScore << firstDelimiter;
        // House time
        myfile << house.location<<firstDelimiter;
        myfile << house.description<<firstDelimiter;
        myfile << house.house_Rating<<firstDelimiter;
        myfile << house.city<<firstDelimiter;
        myfile << house.periodForOccupy.toString() << firstDelimiter;
        for (string review : house.userReviews){
            myfile << review << secDelimiter;
        }
        myfile << firstDelimiter;
        for (Request request : house.requestsToOccupy){
            myfile << request.toString() << secDelimiter;
        }
        myfile << "\n";
    }
    myfile.close();
}



int main() {
    std::cout << "Hello World!";
    vector<Member> memberVec = {};
    vector<House> houseVec = {};
    vector<Request> requestVec = {};

    memberVec.push_back(Member("Nguyen Huu Khang","metalbox","password",69988139));
    memberVec.push_back(Member("Khanh Lin","lnnnnnn","password2",12324333));
    memberVec[0].showInfo();    
    Member &khang = memberVec[0];
    houseVec.push_back(House("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean", "Fresh Air", "Cheap"},{Request(&memberVec[1],Period(11,1,2022,12,2,2022))},&khang));
    houseVec[0].showHouseInfo();

    
    saveToFile("database.csv",houseVec, "," , "|||");

    return 0;
}
