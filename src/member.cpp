#include "Member.h"
// #include "main.cpp"



Member::Member(string fullNameVal, string userNameVal, string passwordVal,  int phoneVal, int creditPointVal, double occupierRatingScoreVal, int numOfRatingVal): 
            fullName(fullNameVal), userName(userNameVal), password(passwordVal), phoneNumber(phoneVal),creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal),numOfRatings(numOfRatingVal) {};


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
int &Member::getNumOfRatings(){
    return this->numOfRatings;
}

void Member::calOcuNewScore(){
    int temp;
    cout << "Please rate the member from -10(Very Dislikke) to 10(Very like): ";
    cin >> temp;
    while (temp < -10 || temp > 10)
    {
        cout << "Please enter a number from -10(Very Dislikke) to 10(Very like): ";
        cin >> temp;
    }
    occupierRatingScore = ((occupierRatingScore * numOfRatings) + temp) / (numOfRatings + 1);
    numOfRatings += 1;
}

void Member::showInfo(){
    string tempt;
    cout << "\n";
    cout << "Full name= " << fullName << "\n";
    cout << "UserName= " << userName << "\n";
    cout << "Password= " << password << "\n";
    cout << "PhoneNumber= " << phoneNumber << "\n";
    cout << "Credit point= " << creditPoint << "\n";
    cout << "Occupation score= " << occupierRatingScore << "\n";

}
