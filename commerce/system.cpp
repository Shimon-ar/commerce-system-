//
// Created by Shimon Arshavsky on 11/12/2019.

#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "system.h"
#include "User.h"
#include "DynamicArray.h"
#include "Seller.h"
#include "Buyer.h"
#include "Items.h"
#include "Item.h"
#include <typeinfo>


using namespace std;

const int MAX_SIZE = 20;

System::System(const string &System_name) : system_name(System_name) {}


System::~System() {//free all the users
    for (int i = 0; i < allUsers.getSize(); i++)
        delete allUsers.getElement(i);
	auto itr = allItems.GetItems().begin();
	auto itrEnd = allItems.GetItems().end();
	for (; itr != itrEnd; ++itr)//free the items
		delete *itr;

}

User *System::LogIn(const string &user_name, const string &password) {
    for (int i = 0; i < allUsers.getSize(); i++) {//pass on all the users and check if there a match
        User *user = allUsers.getElement(i);
        if (user_name== user->GetUserName()  &&
           password== user->GetPassword())
            return user;
    }
    return nullptr; //didnt find any
}

void System::operator()(const string &type_user) {//operator to print base on what you want to print
	int count = 0;
	for (int i = 0; i < allUsers.getSize(); i++) {
		User *user = allUsers.getElement(i);//get the user and check if he is seller buyer or buyer seller and print accordingly to type user
		if (type_user== "Seller"  && typeid(*user) == typeid(Seller))
		{
			cout << *user << "\n";
			count++;
		}

		if (type_user== "Buyer" && typeid(*user) == typeid(Buyer))
		{
			cout << *user << "\n";
			count++;
		}
		if (type_user== "BuyerSeller" && typeid(*user) == typeid(BuyerSeller))
		{
			cout << *user << "\n";
			count++;
		}
	}
		if (count == 0)
			cout << "there is no " << type_user << "s in the system\n";
	
}

const System &System::operator+=(const Buyer &buyer) {//add buyer
    Buyer *newBuyer = new Buyer(buyer);
    allUsers += newBuyer;
    return *this;
}

const System &System::operator+=(const Seller &seller) {//add seller
    Seller *newSeller = new Seller(seller);
    allUsers += newSeller;
    return *this;
}

const System &System::operator+=(const BuyerSeller &buyerSeller) {//add buyerseller
    BuyerSeller *newBuyerSeller = new BuyerSeller(buyerSeller);
    allUsers += newBuyerSeller;
    return *this;
}

const User *System::searchUserByName(const string &name) const
//return pointer to user if exists else nullptr
{
    for (int i = 0; i < allUsers.getSize(); i++) {
        User *user = allUsers.getElement(i);//pass on the users and search for match between the names
        if (user->GetUserName() == name)
            return user;
    }
    return nullptr;
}

//const User &operator>(const Buyer &buyer1, const Buyer &buyer2) {//compare base on the sum
//    return buyer1.Sum() > buyer2.Sum() ? buyer1 : buyer2;
//}

void System:: saveUsers(string fileName) const
{
	ofstream outfile(fileName, ios::trunc);
	outfile << allUsers.getSize() << "\n";
	for (int i = 0; i < allUsers.getSize(); i++)
	{
		User * user = (allUsers.getElement(i));
		if (typeid(*user) == typeid(Seller))
			outfile << "Seller" << "\n";
		else if (typeid(*user) == typeid(Buyer))
			outfile <<"Buyer"  << "\n";
		else
			outfile << "BuyerSeller" << "\n";
		outfile << *user;
	}
	outfile.close();
}
void System::uploadUsers(string filename)
{
	ifstream inFile(filename, ios::in);
	
	int numOfUsers;
	inFile >> numOfUsers;
	for (int i = 0; i < numOfUsers; i++) {
		User * user;
		string type,user_name, password, state, city, street,fix;
		getline(inFile, fix);//fix the speces
		getline(inFile, type);
		getline(inFile, user_name);
		getline(inFile, password);
		getline(inFile, state);
		getline(inFile, city);
		getline(inFile, street);
		int number;
		inFile >> number;
		if (type == "Seller")
			user = new Seller(user_name, password, Address(state, city, street, number));
		else if (type == "Buyer")
			user = new Buyer(user_name, password, Address(state, city, street, number));
		else
			user = new BuyerSeller(user_name, password, Address(state, city, street, number));
		allUsers += user;
	}
	inFile.close();
}

















