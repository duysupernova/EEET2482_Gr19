#include <iostream>

using std::cout;
using std::cin;
using std::string;

class Admin {
    private:
    string usernameAdmin = {"Admin"};
    string passwordAdmin = {"12345"};

    public:
    int adminLogin();
    int loggedin = 0;

    void showMemberList();
    void showHouseList();
};