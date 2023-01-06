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

void Menu::guestMenu(){
    int input = 0;
    do {
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
            // Guest :: registerAccount()
            break;
        case 3:
            // memberMenu();
            break;
        case 4:
            // mainMenu();
            break;
        case 5:
            // endProgram();
            break;
        default:
            cout << "Please enter an option!" << endl;
            break;
        } 
    } while (input != 5);
}

void Menu::memberMenu() {
    int input = 0;
    do {
        cout << "Hello traveler!";
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
            //Search house on listing
        case 8:
            //Make request
            break;
        case 9:
            //View status of house request
            break;
        case 10:
            //Rate house
        case 11:
            //Go back
            break;
        case 12:
            //End program
            break;       
        default:
            break;
        }
    } while (input != 12);
}

void Menu::adminMenu(){
    int input = 0;
    do {
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
            // go back
            break;
        case 4:
            // end program
            break;
        default:
            cout << "Please enter an option!" << endl; 
            break;
        } 
    } while (input != 4);
}

void Menu::mainMenu(){
    cout << "******************************************************" << endl;
    cout << "        VACATION HOUSE EXCHANGE APPLICATION" << endl;
    cout << "******************************************************" << endl;
    int input = 0;
    do {
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
            guestMenu();
            break;
        case 2:
        cout << "2" << endl;
            memberMenu();
            break;
        case 3:
        cout << "3" << endl;
            adminMenu();
            break;
        case 4:
        cout << "4" << endl;
            // endProgram();
            break;
        default:
            cout << "Please enter an option!" << endl;
        }
    } while (input != 4);
}

void Menu::checkLogin(vector<Member> &memberVec){
    int exist;
    string userName_val;
    cout << "Enter username: ";
    cin >> userName_val;
    string password_val;
    cout << "Enter password: ";
    cin >> password_val;
    for (int i =0; i < memberVec.size() ; i++) {
        if (userName_val == memberVec[i].getFullName()) {
            exist = 1;
        }
    }
    if (exist == 1 ) {
        cout << "Welcome, " << userName_val << "! We glad you are here.";
        memberMenu();
    } 
    else {
        cout << "Fail to login. If you dont have an account, please register!" << endl;
        mainMenu();
    }
}

void Menu::registerAccount(vector<Member> &memberVec){
    system("cls");
    string fullName, userName, phoneNumber, password;
    cout << "Please provide your name: ";
    cin >> fullName;
    cout << "Please provide your phone number: ";
    cin >> phoneNumber;
    cout << "Please enter your user name: ";
    cin >> userName;
    cout << "Please enter your password: ";
    cin >> password;
    for (int i =0; i < memberVec.size() ; i++) {
        if( fullName == memberVec[i].getFullName()) {
            cout << "Sorry! This user name has been taken. Please try again!" << endl;
            checkLogin(memberVec);
        }
        else {
            memberVec.push_back(Member(fullName, userName, password, std::stoi(phoneNumber)));
            cout << "Successfull register!" << endl;
            cout << "Welcome, " << fullName << "! We glad you are here.";
            memberMenu();
        }
    }
}