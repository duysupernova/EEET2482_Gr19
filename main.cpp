// Your First C++ Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "period.h"
#include "house.h"
#include "member.h"
#include "request.h"

using std::stoi;
using std::stod;

void saveToFile(string fileName, vector<House> &houseVec, char firstDelimiter, char secDelimiter) {
    cout << "Start saving data to file\n";
    std::fstream myfile;
    myfile.open(fileName,std::ios::out);
    // First loop for saving Members and Houses to file
    for (House house : houseVec){
        // Member time
        cout << "House accessed\n";
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
        myfile << house.house_Rating<<firstDelimiter; 
        myfile << house.numOfRatings<<firstDelimiter;
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

void loadFromFile(string fileName,vector<Member> &memberVect, vector<Request> &requestVect,  vector<House> &houseVect, char fDelimit, char sDelimit){
    std::fstream myfile;
    myfile.open(fileName,std::ios::in);
    
    int indexOfHouse = 0;

    string temptFName, temptUName, temptPass, temptPhone, temptCredPoint, temptOccupierRat, temptNumRatings;
    string temptLocation, temptDescript, temptCity, temptHRating, temptHNumRatings;   
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
            houseVect.push_back(House(temptLocation,temptDescript,temptCity,stod(temptHRating),stoi(temptHNumRatings),
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
    // Loading Owners into house
    for (int i = 0; i < houseVect.size(); i++){
        houseVect[i].setOwner(&memberVect[i]);
    }

    // LOADING THE REQUESTS TIME
    string reqUserName;
    indexOfHouse = 0;
    cout << "Start loading requests\n";


    myfile.ignore(1,'\n');
    while(!myfile.eof()){
        getline(myfile,reqUserName,fDelimit);
        if(!reqUserName.find("\nNone")){                 // Another new house and this house doesn't havve request
            indexOfHouse += 1;                          // Go to next house
            continue;
        } else if (!reqUserName.find('\n')){
            indexOfHouse += 1;
            reqUserName = reqUserName.substr(1);
        }
        cout << "\n============The index of house==============" << indexOfHouse << "\n"; 

        getline(myfile,sd,'/');
        getline(myfile,sm,'/');
        getline(myfile,sy,'/');
        getline(myfile,ed,'/');
        getline(myfile,em,'/');
        getline(myfile,ey,fDelimit);

        for (int i = 0; i < houseVect.size(); i++){             // Double check if user exist
            if (reqUserName == memberVect[i].getUserName()) {
                houseVect[indexOfHouse].addRequest(Request(reqUserName,Period(stoi(sd),stoi(sm),stoi(sy),stoi(ed),stoi(em),stoi(ey))));
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
    vector<Request> requestVec = {};

    // memberVec.push_back(Member("Nguyen Huu Khang","metalbox","password",69988139,460,12.1,3));
    // memberVec.push_back(Member("Khanh Lin","lnnnnnn","password2",12324333));
    // memberVec.push_back(Member("Khoi","david","password3",763332267,621,9,2));
    // Member &khang = memberVec[0];
    // Member &linh = memberVec[1];
    // houseVec.push_back(House(&memberVec[0],"46 Le Van Ben", "Beautiful garden","Ho Chi Minh",100,1,Period(1,1,2023,21,1,2023)));
    // houseVec.push_back(House(&memberVec[1]));
    // houseVec.push_back(House(&memberVec[2],"16 Mai Van Vinh","Strong and Healthy","Hannoi",7.7,12,Period(1,1,1,1,1,1)));


    // houseVec[0].addReview(linh,"Clean as f, gonna go back again");
    // houseVec[2].addReview(khang,"Feels good man");
    // houseVec[2].addReview(linh,"Lack technology");

    // houseVec[0].addRequest(Request(&memberVec[1],Period(11,1,2023,15,1,2023)));
    // houseVec[0].addRequest(Request(&memberVec[2],Period(19,12,2003,12,3,2004)));
    // houseVec[2].addRequest(Request(&memberVec[0],Period(15,2,2013,12,3,2014)));
 
    
    loadFromFile("database.csv",memberVec,requestVec,houseVec, '~' , '|');
    cout << "Size of house vector :" << houseVec.size() << "\n";


    cout << &memberVec[0] << "\n";
    cout << houseVec[0].getOwner() << "\n";
    memberVec[0].showInfo();

    houseVec[0].getOwner()->showInfo();
    houseVec[0].showHouseInfo();
    
    // houseVec[0].getOwner()->showInfo();
    saveToFile("database.csv",houseVec,'~' , '|');
    return 0;
}
