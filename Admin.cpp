// #include <iostream>
// #include <istream>
// #include <fstream>
// #include <stdlib.h>

// using std::string;
// using std::cin;
// using std::cout;
// using std::ifstream;

// class Admin {
//     private:
//     string Ad_username;
//     string Ad_password;
//     public:
//     int login_form();
// };
// int Admin::login_form(){
//     int exist;
//     string checkUsername, checkPassword;
//     cout << "Please enter admin username: ";
//     cin >> Ad_password;
//     cout << "Please enter admin password: ";
//     cin >> Ad_password;

//     std::fstream AdminData;
//     AdminData.open("AdminData.txt", std::ios::out);

//     if (!AdminData) {
//         std::cerr << "Fail to create/open file \n";
//         return -1;
//     }

//     AdminData << "Admin 12345";
//     AdminData.close();
//     ifstream input("AdminData.txt");

//     while(input >> checkUsername >> checkPassword) {
//         if(checkUsername == Ad_username && checkPassword == Ad_password) {
//             exist = 1;
//         }
//     }
//     input.close();
//     if(exist == 1) {
//         cout << "Welcome, " << Ad_username << "!";
//         cin.get();
//         cin.get();
//         // main_menu();
//     }
//     else {
//         cout << "Failed to log in. Please enter the correct password/username for Admin log in!";
//         cin.get();
//         cin.get();
//         // main_menu();
//     }
//     }
#include "Admin2.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;

int Admin::adminLogin() {
    string username;
    string password;

    //checkLogin
    cout << "Please enter Admin username: ";
    cin >> username;
    cout << "Please enter Admin password";
    cin >> password;

    if(username == usernameAdmin && password == passwordAdmin) {
        Admin::loggedin = 1;
        return 1;
    }
    else {
        return 0;
    }

    //Show member list


    //Show house list

}
