//
// Created by Shimon Arshavsky on 13/12/2019.
//



#ifndef COMMERS_PROJECT_BUYER_H
#define COMMERS_PROJECT_BUYER_H

#include "DynamicArray.h"
#include "Payment.h"
#include "User.h"
#include "Items.h"
#include "Order.h"


class Seller;
class Item;
#include <vector>
class Buyer : virtual public User {//virtual for the grandchild
private:
    Items myItems;//all the items the buyer added
    Order my_order;//his order
    vector<Payment *> my_payments;//payments array
public:
    Buyer(const string &user_name, const string &password, const Address &address);

    Buyer(const Buyer &other);

    virtual ~Buyer();

    bool AddingFeedback(const string &sellerUserName, const string &feedbackText) const;

    int MakingPayment();

    Items &GetItems() { return myItems;  }

    const Order &GetMyOrder() const { return my_order; }

    Order &GetMyOrder() { return my_order; }

    const vector<Payment *> &GetMyPayments() const { return my_payments; }

    const Buyer &operator+=(Item *item);//to add item to his items

    const Buyer &operator>(const Buyer& other) const;//operator for who is bigger


	void showPayments()const;

};

#endif //COMMERS_PROJECT_BUYER_H
