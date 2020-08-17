//
// Created by Shimon Arshavsky on 13/12/2019.
//

#include <iostream>

#include "Items.h"
#include "Item.h"

using namespace std;

Items::Items() : itemsList() {}

bool Items::ShowItemsByName(const string & name) const {//show all the items with the exact name
    bool exist = false;
	auto  itr = itemsList.begin();
	auto  itrEnd = itemsList.end();
    for (; itr!=itrEnd; ++itr) {
        if ((*itr)->GetName() == name) {
            cout << *(*itr)<<'\n';
            exist = true;
        }
	
    }
    return exist;
}

Item *Items::FindItem(int ID_item) {//find by id returning the item or nullptr if no match
	auto  itr = itemsList.begin();
	auto  itrEnd = itemsList.end();
    for (; itr != itrEnd; ++itr) {
		if ((*itr)->GetId() == ID_item)
			return *itr;
    }
    return nullptr;
}
int Items::getSum() const 
{
	int sum = 0;
	if (itemsList.size() == 0)
		return 0;
	auto itr = itemsList.begin();
	auto itrEnd = itemsList.end();
	for (; itr != itrEnd; ++itr)
		sum += (*itr)->GetPrice();
	return sum;
}
void Items::showItems()const
{
	if (itemsList.size() == 0)
	{
		cout << "there is no items\n";
		return;
	}
	auto  itr = itemsList.begin();
	auto  itrEnd = itemsList.end();
	for (; itr != itrEnd; ++itr) {
		cout << *(*itr);
	}
}




