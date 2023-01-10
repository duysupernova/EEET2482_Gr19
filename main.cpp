// Your First C++ Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "period.h"
#include "house.h"
#include "member.h"
#include "request.h"
#include "menu.h"


void saveToFile(string fileName, vector<House> &houseVec, char firstDelimiter, char secDelimiter) {
    std::fstream myfile;
    myfile.open(fileName,std::ios::out);
    // First loop for saving Members and Houses to file
    for (House house : houseVec){
        // Member time
        myfile << house.owner->fullName << firstDelimiter;         // VSCode says it's inacessible
        myfile << house.owner->userName << firstDelimiter;         // But it is acessible
        myfile << house.owner->password << firstDelimiter;
        myfile << house.owner->phoneNumber << firstDelimiter;
        myfile << house.owner->creditPoint << firstDelimiter;
        myfile << house.owner->occupierRatingScore << firstDelimiter;
        myfile << house.owner->numOfRatings << firstDelimiter;
        // House time
        myfile << house.location<<firstDelimiter;
        myfile << house.description<<firstDelimiter;
        myfile << house.city<<firstDelimiter;
        myfile << house.houseRating<<firstDelimiter; 
        myfile << house.numOfRatings<<firstDelimiter;
        myfile << house.minOccupierRating<<firstDelimiter;
        myfile << house.ptPerDay<<firstDelimiter;
        myfile << house.periodForOccupy.toString() << firstDelimiter;
        for (string review : house.userReviews){
            myfile << review << firstDelimiter;
        }
        myfile << "\n";
    }
    // Second loop for saving requests
    myfile << "REQUESTS" << firstDelimiter << "\n";                 // Cue to know that these are requests data now

    for (House house : houseVec) {
        if (house.requestsToOccupy.size() == 0){
                myfile << "None" << firstDelimiter << "\n";
        } else {
            for (Request request : house.requestsToOccupy){
                myfile << request.toString() << firstDelimiter;
            }
            myfile << "\n";
        }
    }
    myfile.close();
}

void loadFromFile(string fileName,vector<Member> &memberVect,vector<House> &houseVect, char fDelimit){
    std::fstream myfile;
    myfile.open(fileName,std::ios::in);
    
    int indexOfHouse = 0;

    string temptFName, temptUName, temptPass, temptPhone, temptCredPoint, temptOccupierRat, temptNumRatings;
    string temptLocation, temptDescript, temptCity, temptHRating, temptHNumRatings, temptMinOccuRating, temptPointPDay;   
    string sd,sm,sy,ed,em,ey;
    string temptReview;

    getline(myfile,temptFName,fDelimit);
    while(!myfile.eof()){
        cout << "\n============The index of iteration=================== " << indexOfHouse << "\n"; 
        // MEMBER Time
        if (!temptFName.find("REQUESTS")){               
            cout << "Requests loading time\n";
            break;
        }                                   
        getline(myfile,temptUName,fDelimit);
        getline(myfile,temptPass,fDelimit);
        getline(myfile,temptPhone,fDelimit);
        getline(myfile,temptCredPoint,fDelimit);
        getline(myfile,temptOccupierRat,fDelimit);
        getline(myfile,temptNumRatings,fDelimit);
        memberVect.push_back(Member(temptFName,temptUName,temptPass,stoi(temptPhone),stoi(temptCredPoint),stod(temptOccupierRat),stoi(temptNumRatings)));
        cout << &memberVect[indexOfHouse] << "\n";                  // DEBUGGGINGNGG

        // HOUSE Time
        getline(myfile,temptLocation,fDelimit);
        getline(myfile,temptDescript,fDelimit);
        getline(myfile,temptCity,fDelimit);
        getline(myfile,temptHRating,fDelimit);
        getline(myfile,temptHNumRatings,fDelimit);
        getline(myfile,temptMinOccuRating,fDelimit);
        getline(myfile,temptPointPDay,fDelimit);
        // get period time
        getline(myfile,sd,'/');
        getline(myfile,sm,'/');
        getline(myfile,sy,'/');
        getline(myfile,ed,'/');
        getline(myfile,em,'/');
        getline(myfile,ey,fDelimit);
        // Start loading into object
        cout << &memberVect[indexOfHouse] << "\n";                  // DEBUGGGINGNGG
        if(temptLocation == ""){
            houseVect.push_back(House());
            cout << "Empty house loaded into vector!\n";
        } else {
            houseVect.push_back(House(nullptr,temptLocation,temptDescript,temptCity,stod(temptHRating),stoi(temptHNumRatings),stod(temptMinOccuRating),stoi(temptPointPDay),
                                        Period(stoi(sd),stoi(sm),stoi(sy),stoi(ed),stoi(em),stoi(ey))));
            cout << "A house loaded into vector\n";
        }    
        // Loading REVIEWS into object
        getline(myfile,temptReview,fDelimit);
        while (temptReview.find('\n')){                      // Isnt at the end of the line
            houseVect[indexOfHouse].userReviews.push_back(temptReview);
            cout << "Load a reivew in house:" << temptReview << "\n";   // for debugging
            getline(myfile,temptReview,fDelimit);
        }
        temptFName = temptReview.substr(1);          // The temptReview acutally gets the string below which belongs to another user.
        


        indexOfHouse++;

    }
    // Loading Owners pointers into house
    for (int i = 0; i < houseVect.size(); i++){
        houseVect[i].setOwner(&memberVect[i]);
    }

    // LOADING THE REQUESTS TIME
    string reqUserName;
    string isAcceptedString;
    indexOfHouse = 0;
    cout << "Start loading requests\n";


    myfile.ignore(1,'\n');
    while(!myfile.eof()){
        getline(myfile,reqUserName,fDelimit);
        if(!reqUserName.find("\nNone")){                 // Another new house and this house doesn't have request
            indexOfHouse += 1;                          // Go to next house
            continue;
        } else if (!reqUserName.find('\n')){
            indexOfHouse += 1;
            reqUserName = reqUserName.substr(1);
        }
        cout << "\n============The index of house==============" << indexOfHouse << "\n";       // For debugging

        getline(myfile,sd,'/');
        getline(myfile,sm,'/');
        getline(myfile,sy,'/');
        getline(myfile,ed,'/');
        getline(myfile,em,'/');
        getline(myfile,ey,fDelimit);
        getline(myfile,isAcceptedString,fDelimit);
        
        for (int i = 0; i < houseVect.size(); i++){             // Double check if user exist
            if (reqUserName == memberVect[i].getUserName()) {
                houseVect[indexOfHouse].addRequest(Request(reqUserName,Period(stoi(sd),stoi(sm),stoi(sy),stoi(ed),stoi(em),stoi(ey)),stoi(isAcceptedString)));
                cout << "A request made by " << memberVect[i].getUserName() << " loaded\n";

            }
        }
    }



    myfile.close();
}

int main() {
    std::cout << "Hello World!\n";
    vector<Member> memberVec = {};
    vector<House> houseVec = {};
    int currentMemberIndex = -1;
    loadFromFile("database.csv",memberVec,houseVec,'~');
    Menu menu;
    menu.mainMenu(currentMemberIndex,memberVec,houseVec);

    saveToFile("database.csv",houseVec, '~' , '|');

    return 0;
}
