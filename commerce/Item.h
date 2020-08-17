//
// Created by Shimon Arshavsky on 13/12/2019.
//
#pragma warning (disable:4996)
#ifndef COMMERS_PROJECT_ITEM_H
#define COMMERS_PROJECT_ITEM_H
#include <string>
#include <iostream>
#include "Seller.h"
using namespace std;
class Seller;

class Item{
public:
    enum Category{Office , Clothes , Kids , Electricity};
    char CategoryArr[4][12] = {"Office" , "Clothes" , "Kids" , "Electricity"};//easy way to get the value of enum
private:
    static int id_num;//counter
    int id_item;
	string item_name;
    int price;
    Seller* seller;
    Category type_item;
public:
    Item(const string & item_name , int price , Seller* seller , Category type_item);
    Item(Item& other) = delete; //items cannot be copied
    ~Item();

    inline int GetId() const { return id_item;}
    inline const string & GetName() const {return item_name;}
    inline int GetPrice() const { return price;}
    Seller& GetSeller() {return *seller;}
    inline const Seller& GetSeller() const {return *seller;}
	inline Category getCategory()const { return type_item; }
    static bool validPrice(int price){return price>0;}//static functions to check the data
    static bool validCategory(Category type_item){ return (((int)type_item)>=0 && ((int)type_item)<4);}

	friend ostream& operator<<(ostream &os, const Item & item)
	{
		os << "item id: " << item.id_item << endl;
		os << "item name: " << item.item_name << endl;
		os << "item category: " << item.CategoryArr[item.type_item] << endl;//לגשת למערך
		os << "price: " << item.price << endl;
		os << "seller: " << *(item.seller);
		return os;
	}
	void showItem()const 
	{
		cout << "item id: " << id_item << endl;
		cout << "item name: " << item_name << endl;
		cout << "item category: " << CategoryArr[type_item] << endl;//לגשת למערך
		cout << "price: " << price << endl;
		cout << "seller: " << *(seller);
		
	}
};

#endif //COMMERS_PROJECT_ITEM_H
