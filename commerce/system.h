//
// Created by Shimon Arshavsky on 11/12/2019.
//


#ifndef COMMERS_PROJECT_SYSTEM_H
#define COMMERS_PROJECT_SYSTEM_H

#include <iostream>
#include <string>
#include "User.h"
#include "Seller.h"
#include "BuyerSeller.h"
#include "Buyer.h"
#include "DynamicArray.h"
#include "Items.h"
#include <fstream>
using namespace std;


class System//this class have array of all users sellers items and buyers and doing actions accordingly
{
private:
    string system_name;//name system
    DynamicArray<User*> allUsers;//array of all users
    Items allItems;//all the items
public:
    System(const string & system_name );
    System(const System& other) = delete;
    ~System();

    const DynamicArray<User*>& GetUsers()  const { return allUsers;}
    const Items& GetAllItems() const { return allItems;}
    Items& GetAllItems() { return allItems;}
    User* LogIn(const string &user_name, const string &password);
	void operator()(const string & type_user);//print the users base on the type
	const System&operator+=(const Seller& seller);//overloaded functions to add user
    const System&operator+=(const Buyer& buyer);
    const System&operator+=(const BuyerSeller& seller);
    friend const User& operator>(const Buyer& buyer1 , const Buyer& buyer2);//compare between buyers
    const User* searchUserByName(const string & name)const;//search user by name
	void saveUsers(string fileName="users.txt")const ;
	void uploadUsers(string fileName = "users.txt");
};



#endif //COMMERS_PROJECT_SYSTEM_H
