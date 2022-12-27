#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <stdlib.h>


using namespace std;

class Guest{
    private:
    string guestFullName;
    string guestUserName;
    string guestPassword;
    int guestPhone;
    public:
    Guest(string guestFullName = " ", string guestUserName = " ", string guestPassword = " ", int guestPhoneVal = 0) : guestFullName(guestFullName), guestUserName(guestUserName), 
                                                                                                guestPassword(guestPassword), guestPhone(guestPhoneVal){

    }

    void register_form();
    void display_house();
};

class Member : public Guest{
    private:
        string fullName;
        string userName;
        string password;
        int phone;
        int creditPoint;
        int occupierRatingScore;
        // House houseForRent;
    public:
        Member(string fullName = " ", string userName = " ", string password = " ", int phone = 0, int creditPointVal = 500, int occupierRatingScoreVal = 0) : Guest(fullName, userName, password, phone),
        creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal){

        } 
        void login_form();
};


void Guest::register_form(){
    system("cls");
    cout << "Please provide your name: ";
    cin >> guestFullName;
    cout << "Please provide your phone number: ";
    cin >> guestPhone;
    cout << "Please enter your user name: ";
    cin >> guestUserName;
    cout << "Please enter your password: ";
    cin >> guestPassword;

    ofstream reg("database.txt", ios::app);
    reg << guestFullName << ' ' << guestPassword << endl;
    system("cls");
    cout << "Registration is successfull!" << endl << endl;
}

void main_menu(){
    Guest g;
    Member m;
    int select_option;
        cout << "******************************************************" << endl;
        cout << "        VACATION HOUSE EXCHANGE APPLICATION" << endl;
        cout << "******************************************************" << endl;
        cout << "                       Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Guest" << endl;
        cout << "2. Member" << endl;
        cout << "3. Admin" << endl;
        cout <<"\nEnter your Choice: ";
	cin >> select_option;
	switch (select_option)
    {
        case 0:
            cout << "Exit";
            break;
		case 1:
			g.register_form();
            main_menu();
			break;
        case 2:	
            m.login_form();
            break;
		case 3:	
            cout <<"Success 3" << endl;
            break;
        default:
        cout <<"\nCo cai loz: " << endl;
        main_menu();
    }
}

void Member::login_form(){
    int exist;
    string checkUser, checkPassword;
    system("cls");
    cout << "Username: ";
    cin >> userName;
    cout << "Password: ";
    cin >> password;

    ifstream input("database.txt");

    while(input >> checkUser >> checkPassword) {
        if(checkUser == userName && checkPassword == checkPassword) {
            exist = 1;
        }
    }
    input.close();
    if(exist == 1) {
        cout << "Welcome, " << userName << "! We glad you are here.";
        main_menu();
    }
    else {
        cout << "Fail to login. If you dont have an account, please register!" << endl;
        main_menu();
    }
    }

int main(){
    main_menu();
    return 0;
}