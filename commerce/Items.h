//
// Created by Shimon Arshavsky on 13/12/2019.
//

#ifndef COMMERS_PROJECT_ITEMS_H
#define COMMERS_PROJECT_ITEMS_H
#include <list>
#include "DynamicArray.h"
#include <iostream>

using namespace std;

class Item;



class Items {//class of items that contains array of items
private:
    list <Item *> itemsList;
public:
    Items();
	int getSize()const { return itemsList.size(); }
    const list<Item *> &GetItems() const { return itemsList; }
	int getSum() const;
	list<Item *> &GetItems() { return itemsList; }
	void showItems()const;
    Item *FindItem(int ID_item) ;//

    bool ShowItemsByName(const string & name) const;

	const Items &operator+=(Item * item)
	{
		this->itemsList.push_back(item);
		return *this;
	}

};

#endif //COMMERS_PROJECT_ITEMS_H
