#include "Member.h"
// #include "main.cpp"



Member::Member(string fullNameVal, string userNameVal, string passwordVal,  int phoneVal, int creditPointVal, double occupierRatingScoreVal, int numOfOperating): 
                fullName(fullNameVal), userName(userNameVal), password(passwordVal), phoneNumber(phoneVal),creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal), numOfOperating(numOfOperating){};


string &Member::getFullName(){
    return this->fullName;
}
string &Member::getUserName(){
    return this->userName;
};
string &Member::getPassword(){
    return this->password;
};
int &Member::getPhoneNumber(){
    return this->phoneNumber;
};
int &Member::getCreditPoint(){
    return this->creditPoint;
};
double &Member::getOccupierScore(){
    return this->occupierRatingScore;
}
int &Member::getNumOfOperating(){
    return this->numOfOperating;
}

void Member::calOcuNewScore(int temp){
    cout << "Please rate the member from -10(Very Dislikke) to 10(Very like): ";
    cin >> temp;
    while (temp < -10 || temp > 10)
    {
        cout << "Please enter a number: ";
        cin >> temp;
    }
    occupierRatingScore = ((occupierRatingScore * numOfOperating) + temp) / (numOfOperating + 1);
}

void Member::showInfo(){
    cout << "\n";
    cout << "Full name= " << fullName << "\n";
    cout << "userName= " << userName << "\n";
    cout << "password= " << password << "\n";
    cout << "phoneNumber= " << phoneNumber << "\n";
    cout << "credit point= " << creditPoint << "\n";
    cout << "Occupation score= " << occupierRatingScore << "\n";
}
