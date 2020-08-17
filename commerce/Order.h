//
// Created by Shimon Arshavsky on 14/12/2019.
//

#ifndef COMMERS_PROJECT_ORDER_H
#define COMMERS_PROJECT_ORDER_H

#include "Items.h"
#include "Item.h"
#include "User.h"
#include <iostream>

using namespace std;

class Order {

private:
    Items items;//the items in order
    const string  buyerName;//user cant be change
    int orderPrice;//price order
public:
    Order(const string & username) : buyerName(username),orderPrice(0) {}//initial order

    Order(const Order &other):buyerName(other.buyerName),orderPrice(other.orderPrice){//copy the order
        items.GetItems() = other.items.GetItems();
    }

    ~Order(){
      
    }

    const string & getBuyer() const{ return buyerName; }

    const Items &GetItems() const { return items; }

    Items & GetItems() { return items; }

    const Order &operator+=( Item *item) {
        items += item;
        orderPrice+=item->GetPrice();
        return *this;
    }

    void MakeEmpty(){//empty the order
        orderPrice=0;
		items.GetItems().erase(items.GetItems().begin());
    }

    friend ostream &operator<<(ostream &os, const Order &other) {//print the order
        os << "\nOrder for: " << other.buyerName << "\n" ;
        other.GetItems().showItems();
           os<< "Order price: " << other.orderPrice << "\n"
           << "-----     end order      -----\n";
        return os;
    }
	void showOrder()const
	{
		cout << "\nOrder for: " << buyerName << "\n";
		items.showItems();
		cout << "Order price: " << orderPrice << "\n";
		cout	<< "-----     end order      -----\n";
	}


};


#endif //COMMERS_PROJECT_ORDER_H
