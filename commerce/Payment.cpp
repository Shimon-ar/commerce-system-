//
// Created by Shimon Arshavsky on 15/12/2019.
//


#include "Buyer.h"
#include "Seller.h"
#include "Item.h"
#include "Payment.h"
#include <iostream>
#include "DynamicArray.h"

using namespace std;

Payment::Payment(const Buyer &buyer, Seller &seller, Item *item)
        : buyer(&buyer), seller(&seller) {
    this->items += item;
    totalAmount = item->GetPrice();
}

const Payment &Payment::operator+=(Item *item) {
    items += item;
    totalAmount += item->GetPrice();
    return *this;
}

ostream &operator<<(ostream &os, const Payment &other) {
    os << "Payment for: " << other.buyer->GetUserName()
       << '\n' << "Total amount: " << other.totalAmount << '\n' << "Items: " << '\n' ;
    other.items.showItems();
    os<< "\n"
       << "-----     end payment    -----";
    return os;
}

