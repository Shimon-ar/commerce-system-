//
// Created by Shimon Arshavsky on 14/12/2019.
//

#include "Seller.h"
#include <iostream>
#include "Items.h"
#include "Item.h"
#include "FeedBack.h"
#include "User.h"

using namespace std;


Seller::Seller(const Seller &other):User(other.GetUserName(),other.GetPassword(),other.GetAddress()) {
    allFeedback = other.allFeedback;
    myItems.GetItems() = other.myItems.GetItems();
}

Seller::~Seller() {
	
	auto itr = allFeedback.begin();
	auto itrEnd = allFeedback.end();
	for (; itr != itrEnd; ++itr)
		delete *itr;//delete all the feedbacks
}

void Seller::AddNewItem(Items &allItems, const string &name, int price, int category) {//create new item
    Item *newItem = new Item(name, price, this, (Item::Category) category);
    myItems += newItem;     //adding to his items
    allItems += newItem;//adding to all items
}
void Seller::showFeedBacks()const
{
	if (allFeedback.size() == 0)
		cout << "there is no feedbacks\n";
	auto itr = allFeedback.begin();
	auto itrEnd = allFeedback.end();
	for (; itr != itrEnd; ++itr)
		cout << *(*itr)<<endl;
}

