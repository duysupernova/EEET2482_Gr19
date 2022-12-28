#include "member.h"


Member::Member(string fullNameVal = "", string userNameVal = "", string passwordVal = "",  int phoneVal = 0, int creditPointVal = 500, int occupierRatingScoreVal = 0) 
    : Guest(fullNameVal, userNameVal, passwordVal, phoneVal),creditPoint(creditPointVal), occupierRatingScore(occupierRatingScoreVal), houseForRent(House()){};

string Member::getUserName(){
    return this->userName;
};

void Member::addHouse (House &house){
    this->houseForRent = house;
}
void Member::requestToOccupy(House &house,int sd,int sm,int sy,int ed, int em,int ey){
    house.addRequest(Request(*this,Period(sd,sm,sy,ed,em,ey)));
};