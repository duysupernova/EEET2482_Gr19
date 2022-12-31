#include "Member.h"


Member::Member(string fullNameVal, string userNameVal, string passwordVal,  int phoneVal, int creditPointVal, int occupierRatingScoreVal): 
                fullName(fullNameVal), userName(userNameVal), password(passwordVal), phoneNumber(phoneVal),creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal){};


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
int &Member::getOccupierScore(){
    return this->occupierRatingScore;
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

// void Member::addHouse (House *house){
//     house->owner = this;
// }

// void Member::requestToOccupy(House &house,int sd,int sm,int sy,int ed, int em,int ey){
//     house.addRequest(Request(*this,Period(sd,sm,sy,ed,em,ey)));
// };

// int main(){
// /*TESTING PURPOSES*/
//     Member m1("Nguyen Huu Khang","metalbox","password",12344442);
//     m1.showInfo();
// }
