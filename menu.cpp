#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <stdlib.h>


using namespace std;

class guest{
    private:
    string guestFullName;
    string guestUserName;
    string guestPassword;
    int guestPhone;
    public:
    void register_form();
    void display_house();
};

class member{
    private:
        string fullName;
        string userName;
        string password;
        int phone;
        int creditPoint = 500;
        int occupierRatingScore = 0;
    public:
        void login_form();
};


void guest::register_form(){
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

void member::login_form(){
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
        cin.get();
        cin.get();
        // main_menu();
    }
    else {
        cout << "Fail to login. If you dont have an account, please register!";
        cin.get();
        cin.get();
        // main_menu();
    }
    }

void main_menu(){
    guest g;
    member m;
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

int main(){
    main_menu();
    return 0;
}