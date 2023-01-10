#include<iostream>
#include<vector>
#include "menu.h"
#include "house.h"
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
        cout << "*====GUEST====*" << endl;
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
            showHousesInfoMini(houseVec);                       // DONE
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
        cout << "Hello traveler " << memberVec[currUserIndex].getUserName() <<"!"<<  endl;
        cout << "[1] Information" << endl;
        cout << "[2] Register & Change house infomation" << endl;
        cout << "[3] List house for occupation" << endl;
        cout << "[4] Un-list House" << endl;
        cout << "[5] View and Accept request" << endl;
        cout << "[6] Rate occupier" << endl;
        cout << "[7] Search house for rent & make request" << endl;
        cout << "[8] View status of my requests" << endl;
        cout << "[9] Rate house" << endl;
        cout << "[10] Review house" << endl;
        cout << "[11] Log out" << endl;
        cout << "[12] End program" << endl;
        cout << "Please enter an option: ";
        cin >> input;

        switch (input)
        {
        case 1:
            houseVec[currUserIndex].showInfoFull();                     // DONE                
            break;
        case 2:
            houseVec[currUserIndex].registerHouseMenu();                // DONE
            break;
        case 3:
            houseVec[currUserIndex].listHouse();                        // Done
            break;
        case 4: 
            houseVec[currUserIndex].unlistHouse();                      // DONE
            break;
        case 5:
            houseVec[currUserIndex].acceptRequest(memberVec);           // DONE
            break;
        case 6:
            houseVec[currUserIndex].rateOccupier(houseVec);             // DONE
            break;
        case 7:
            houseVec[currUserIndex].sreachHouse(houseVec);              // DONE
            break;
        case 8:
            houseVec[currUserIndex].viewRequestsMade(houseVec);         // DONE
            break;
        case 9:
            houseVec[currUserIndex].rateHouse(houseVec);                // DONE
            break;
        case 10:
            houseVec[currUserIndex].reviewHouse(houseVec);              // DONE
            break;
        case 11:
            //Go back                                       
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
    Admin admin;
    do {
        system("cls");
        cout << "*====ADMIN====*" << endl;
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
            admin.showHouseList(houseVec);
            break;
        case 2:
            admin.showMemberList(memberVec);
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
void Menu::adminLogin(vector<Member> &memberVec,vector<House> &houseVec) {
    string username, password;
    string usernameAdmin = "Admin";
    string passwordAdmin = "12345";

    //checkLogin
    cout << "Please enter Admin username: ";
    cin >> username;
    cout << "Please enter Admin password: ";
    cin >> password;

    if(username == usernameAdmin && password == passwordAdmin) {
        adminMenu(memberVec,houseVec);
    }
    else {
        cout << "\n\nYou are not admin!\n";
        cout << "Press a character and enter to continue!\n";
        cin >> username;
    }
}
void Menu::mainMenu(int &currUserIndex, vector<Member> &memberVec,vector<House> &houseVec){
    int input = 0;
    do {
        system("cls");
        cout << "******************************************************" << endl;
        cout << "        VACATION HOUSE EXCHANGE APPLICATION" << endl;
        cout << "******************************************************" << endl << endl;
        cout << "Instructors: Mr.Linh Tran & Phong Ngo" << endl;
        cout << "Group: 19" << endl;
        cout << "s3924427, Nguyen Tien" << endl;
        cout << "s3852307, Nguyen Ha Minh Duy" << endl;
        cout << "s3927067, Nguyen Huu Minh Khang" << endl;
        cout << "s3955486, Nguyen Dang Gia Hoang" << endl << endl;
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
            adminLogin(memberVec,houseVec);
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

void Menu::showHousesInfoMini(vector<House> &houseVec){
    string tempt;
    system("cls");
    cout << "====All available houses for occupy====\n";
    for(House house : houseVec){
        if(!Period(3,1,1970,1,1,9999).isInsidePeriod(house.getPeriodForOccupy())){
            house.showInfoMini();
        }
    }
    cout << "\n\nPress a character and enter to continue\n";
    cin >> tempt;
}

void Menu::checkLogin(vector<Member> &memberVec,vector<House> &houseVec){
    int exist = -1;
    string userName_val;
    string password_val;
    int currUserIndex = -1;
    system("cls");
    cout << "Enter username: ";
    cin >> userName_val;
    cout << "Enter password: ";
    cin >> password_val;
    for (int i =0; i < memberVec.size() ; i++) {
        if (userName_val == memberVec[i].getUserName()) {
            if(password_val == memberVec[i].getPassword()){
                currUserIndex = i;
                exist = 1;
            }
        }
    }
    if (exist == 1 ) {
        cout << "Welcome, " << userName_val << "! We glad you are here.";
        memberMenu(currUserIndex,memberVec,houseVec);
    } 
    else {
        cout << "\n\nFail to login. Your password or username is wrong!" << endl;
        cout << "Press a character and enter to return\n";
        cin >> userName_val;
    }
}

void Menu::registerAccount(vector<Member> &memberVec,vector<House> &houseVec){
    system("cls");
    string fullName, userName, phoneNumber, password, tempt;
    cout << "Please provide your name: ";
    cin >> fullName;
    cout << "Please enter your username: ";
    cin >> userName;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Please provide your phone NUMBER: ";
    cin >> phoneNumber;
    for (int i =0; i < memberVec.size() ; i++) {
        if(userName == memberVec[i].getUserName()) {
            cout << "\n\nSorry! This user name has been taken" << endl;
            cout << "Press any character and enter to return\n";
            cin >> tempt;
            return;
        }
    }
    memberVec.push_back(Member(fullName, userName, password, std::stoi(phoneNumber)));
    houseVec.push_back(House());
    for (int i = 0; i < houseVec.size(); i++){
        houseVec[i].setOwner(&memberVec[i]);
    }
    cout << "\n\nSuccessfull register!" << endl;
    cout << "Welcome, " << fullName << "! We glad you are here.";
    cout << "Press any character and enter to continue\n";
    cin >> tempt;
    return;
    }
