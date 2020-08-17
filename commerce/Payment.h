//
// Created by Shimon Arshavsky on 15/12/2019.
//

#ifndef COMMERS_PROJECT_PAYMENT_H
#define COMMERS_PROJECT_PAYMENT_H

#include "Items.h"


using namespace std;

class Buyer;

class Seller;

class Item;

class Payment {//class payment with all the relevant details
private:
    const Buyer *buyer;
    Seller *seller;
    Items items;
    int totalAmount;

public:
    Payment(const Buyer &buyer, Seller &seller, Item *item);

    Payment(const Payment &other) = delete;

    const Buyer * getBuyer() const { return buyer; }

    int GetAmount() const { return totalAmount; }

    Seller* GetSeller() { return seller; }

    const Items &getItems() const { return items; }

    friend ostream &operator<<(ostream &os, const Payment &other);//operator to print payment

    const Payment &operator+=(Item *item);//operator to add payment

};


#endif //COMMERS_PROJECT_PAYMENT_H
