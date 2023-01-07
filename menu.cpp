#include<iostream>
#include<vector>
#include "menu.h"
using namespace std;
    // void mainMenu();
    // void guestMenu();
    // void memberMenu();
    // void adminMenu();
    // void endProgram();
    // void registerAccount();

// int main(){
//     cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
//     cout << "VACATION HOUSE EXCHANGE APPLICATION" << endl;
//     cout << "Instructors: Mr. Linh Tran & Phong Ngo" << endl;
//     cout << "Group: Team 925" << endl;
//     cout << "Nguyen Ha Minh Duy: s3852307" << endl;
//     cout << "Nguyen Ha Minh Duy: s3852307" << endl; 
//     cout << "Nguyen Ha Minh Duy: s3852307" << endl;
//     cout << "Nguyen Ha Minh Duy: s3852307" << endl << endl; 
//     mainMenu();
// return 0 ;    
// }

void endProgram(vector<House> houseVec){
    saveToFile("database.csv",houseVec, '~' , '|');
    system("cls");
    cout << "***********************************\n";
    cout << "*                                 *\n";
    cout << "* Thank you for using our program *\n";
    cout << "*                                 *\n";
    cout << "***********************************\n";
    exit(1);
}

void Menu::guestMenu(vector<Member> &memberVec,vector<House> &houseVec){
    int input = 0;
    do {
        system("cls");
        cout << "Welcome traveler!" << endl;
        cout << "[1] View available houses" << endl;
        cout << "[2] Register as a member" << endl;
        cout << "[3] Login" << endl;
        cout << "[4] Go back" << endl;
        cout << "[5] End program" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            //view available house
            break;
        case 2:
            registerAccount(memberVec,houseVec);                // havent checked user input
            break;
        case 3:
            checkLogin(memberVec,houseVec);                     // DONE
            break;
        case 4:
            // Go back to main menu                             // DONE
            break;
        case 5:
            endProgram(houseVec);                               // DONE
            break;
        default:
            cout << "Please enter an option!" << endl;
            break;
        } 
    } while (input != 4);
}

void Menu::memberMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec) {
    int input = 0;
    do {
        system("cls");
        cout << "Hello traveler! " << memberVec[currUserIndex].getUserName() <<  endl;
        cout << "[1] Information" << endl;
        cout << "[2] List house for occupation" << endl;
        cout << "[3] Un-list House" << endl;
        cout << "[4] View request" << endl;
        cout << "[5] Accept request" << endl;
        cout << "[6] Rate occupier" << endl;
        cout << "[7] Search house on listing" << endl;
        cout << "[8] Make request" << endl;
        cout << "[9] View status of house request" << endl;
        cout << "[10] Rate house" << endl;
        cout << "[11] Go back" << endl;
        cout << "[12] End program" << endl;
        cout << "Please enter an option: ";
        cin >> input;

        switch (input)
        {
        case 1:
            //show full information
            break;
        case 2:
            //List house for occupation
            break;
        case 3:
            //Un-list House
            break;
        case 4:
            //View request
            break;
        case 5:
            //Accept request
            break;
        case 6:
            //Rate occupier
            break;
        case 7:
            houseVec[currUserIndex].sreachHouse(houseVec);
        case 8:
            //Make request
            break;
        case 9:
            //View status of house request
            break;
        case 10:
            //Rate house
        case 11:
            //Go back                                       // DONE
            break;
        case 12:
            endProgram(houseVec);
            break;       
        default:
            break;
        }
    } while (input != 11);
}

void Menu::adminMenu(vector<Member> &memberVec,vector<House> &houseVec){
    int input = 0;
    do {
        system("cls");
        cout << "Welcome admin!" << endl;
        cout << "[1] Show houses information" << endl;
        cout << "[2] Show members information" << endl;
        cout << "[3] Go back" << endl;
        cout << "[4] End program" << endl;
        cout << "Enter your action: ";
        cin >> input;
        switch (input)
        {
        case 1:
            // show house information
            break;
        case 2:
            // show member information
            break;
        case 3:
            // go back                                      // DONE
            break;
        case 4:
            endProgram(houseVec);
            break;
        default:
            cout << "Please enter an option!" << endl; 
            break;
        } 
    } while (input != 3);
}

void Menu::mainMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec){
    cout << "******************************************************" << endl;
    cout << "        VACATION HOUSE EXCHANGE APPLICATION" << endl;
    cout << "******************************************************" << endl;
    int input = 0;
    do {
        system("cls");
        cout << "User the app as:" << endl;
        cout << "[1] Guest" << endl;
        cout << "[2] Member" << endl;
        cout << "[3] Admin" << endl;
        cout << "[4] End program" << endl;
        cout << "Enter your action: ";
        cin >> input;

        switch (input)
        {
        case 1:
            guestMenu(memberVec,houseVec);
            break;
        case 2:
        cout << "2" << endl;
            checkLogin(memberVec,houseVec);
            break;
        case 3:
        cout << "3" << endl;
            adminMenu(memberVec,houseVec);
            break;
        case 4:
        cout << "4" << endl;
            endProgram(houseVec);
            break;
        default:
            cout << "Please enter an option!" << endl;
        }
    } while (input != 4);
}

void Menu::checkLogin(vector<Member> &memberVec,vector<House> &houseVec){
    int exist = -1;
    string userName_val;
    int currUserIndex = -1;
    system("cls");
    cout << "Enter username: ";
    cin >> userName_val;
    string password_val;
    cout << "Enter password: ";
    cin >> password_val;
    for (int i =0; i < memberVec.size() ; i++) {
        if (userName_val == memberVec[i].getUserName()) {
            currUserIndex = i;
            exist = 1;
        }
    }
    if (exist == 1 ) {
        cout << "Welcome, " << userName_val << "! We glad you are here.";
        memberMenu(currUserIndex,memberVec,houseVec);
    } 
    else {
        cout << "Fail to login. If you dont have an account, please register!" << endl;
    }
}

void Menu::registerAccount(vector<Member> &memberVec,vector<House> &houseVec){
    system("cls");
    string fullName, userName, phoneNumber, password;
    cout << "Please provide your name: ";
    cin >> fullName;
    cout << "Please enter your user name: ";
    cin >> userName;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Please provide your phone number: ";
    cin >> phoneNumber;
    for (int i =0; i < memberVec.size() ; i++) {
        if( fullName == memberVec[i].getUserName()) {
            cout << "Sorry! This user name has been taken. Please try again!" << endl;
        }
        else {
            memberVec.push_back(Member(fullName, userName, password, std::stoi(phoneNumber)));
            houseVec.push_back(House());
            for (int i = 0; i < houseVec.size(); i++){
                houseVec[i].setOwner(&memberVec[i]);
            }
            cout << "Successfull register!" << endl;
            cout << "Welcome, " << fullName << "! We glad you are here.";
            return;
        }
    }
}