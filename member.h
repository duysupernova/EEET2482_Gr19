#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "house.h"

class Guest{
    private:
    string guestFullName;
    string guestUserName;
    string guestPassword;
    int guestPhone;
    public:
    Guest(string guestFullName = " ", string guestUserName = " ", string guestPassword = " ", int guestPhoneVal = 0) : guestFullName(guestFullName), guestUserName(guestUserName), 
                                                                                                guestPassword(guestPassword), guestPhone(guestPhoneVal){}
    void register_form();
    void display_house();
};

class Member : public Guest{
private:
    string fullName;
    string userName;
    string password;
    int phoneNumber;
    int creditPoint;
    int occupierRatingScore;
    House houseForRent;
public:
    // Constructor for object member
    Member(string fullName = " ", string userName = " ", string password = " ",  int phone = 0, int creditPointVal = 500, int occupierRatingScoreVal = 0);
    
    string getUserName();

    void addHouse (House &house);
    void requestToOccupy(House &house,int sd,int sm,int sy,int ed, int em,int ey);
    void login_form();
    friend class FileHandling;
};



#endif