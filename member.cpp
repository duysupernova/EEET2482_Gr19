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

//Owners review for a Renter(how well that occupier has taken care of the house)    
    void GetRenter_review(){
        cout<< "Please give review about the renter: ";
        getline(cin, Owner_Review);
        review_Owner.push_back(Owner_Review);
    }

//Owners will rate a renter(how well that occupier has taken care of the house)
    void GetUser_Rating(){ 
        cout << "Please rate quality of the User from -10(Very Dislikke) - 10(Very like): ";
        cin >> Score_For_Renter;

        while (Score_For_Renter> 10 || Score_For_Renter < -10){ //Error check if user input wrong scale value
            cout << "Error!, please rate the User from -10(Very Dislike) - 10(Very like): ";
            cin >> Score_For_Renter;
        }

    }

//averaging the ratings of all house owners who had let their houses to be used by that occupier how well that occupier has taken care of the house. 
    void occupier_rating_score(){
        Total_of_ownerscore += Score_For_Renter; //Get Total of user rating score
        int avgScore_For_Renter = Total_of_ownerscore / Owners; //need to find a way to collect Owners value

    }
