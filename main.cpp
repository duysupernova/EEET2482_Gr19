// Your First C++ Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "period.h"
#include "house.h"
#include "member.h"
#include "request.h"


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
        // myfile << member.houseForRent.location<<",";
        // myfile << member.houseForRent.description<<",";
        // myfile << member.houseForRent.house_Rating<<",";
        // myfile << member.houseForRent.city<<",";
        // myfile << member.houseForRent.periodForOccupy.toString() << ",";
        // for (string review : member.houseForRent.userReviews){
        //     myfile << review << "|||";
        // }
        // myfile << ",";
        // for (Request request : member.houseForRent.requestsToOccupy){
        //     myfile << request.toString() << "|||";
        // }
        myfile << "\n";
    }
    myfile.close();
}

int main() {
    std::cout << "Hello World!";
    vector<Member> memberArr = {};

    Member m1("Nguyen Huu Khang","metalbox","password",12344442);
    m1.showInfo();    
    House h1("46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,Period(1,1,2023,21,1,2023),{"Clean","Fresh Air", "Cheap"},{},&m1);

    memberArr.push_back(m1);

    
    saveToFile("database.csv",memberArr);

    return 0;
}
