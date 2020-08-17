//
// Created by Shimon Arshavsky on 14/12/2019.
//

#ifndef COMMERS_PROJECT_SELLER_H
#define COMMERS_PROJECT_SELLER_H

#include "User.h"
#include "DynamicArray.h"
#include "Items.h"
#include <vector>
class FeedBack;

class Seller : virtual public User {
private:
    vector<FeedBack *> allFeedback;//feedback array
    Items myItems;//all seller items
public:
    Seller(const string &user_name, const string &password, const Address &address) : User(user_name, password, address) {}

    virtual ~Seller();

    Seller(const Seller &other);

    const vector<FeedBack *> &GetAllFeedback() const { return allFeedback; }

	vector <FeedBack *> &GetAllFeedback() { return allFeedback; }

    const Items &GetMyItems() const { return myItems; }

    void AddNewItem(Items &allItems, const string &name, int price, int category);

	const Seller & operator+=(FeedBack * feedback)
	{
		allFeedback.push_back(feedback);
		return *this;
	}
	void showFeedBacks()const;
	

};

#endif //COMMERS_PROJECT_SELLER_H
