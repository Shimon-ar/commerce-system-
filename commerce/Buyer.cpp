//
// Created by Shimon Arshavsky on 13/12/2019.
//

#include <iostream>
#include "Buyer.h"
#include "Items.h"
#include "Item.h"
#include "User.h"
#include "Seller.h"
#include "DynamicArray.h"
#include "Order.h"
#include "FeedBack.h"
#include "Payment.h"


using namespace std;



Buyer::Buyer(const string &user_name, const string &password, const Address &address) : User(user_name, password, address), my_order(user_name) {}//initial the base

Buyer::Buyer(const Buyer &other) : User(other.GetUserName(), other.GetPassword(), other.GetAddress()), my_order(other) {
    myItems.GetItems() = other.myItems.GetItems();
    my_payments = other.my_payments;
}
Buyer::~Buyer() {
	auto itr = my_payments.begin();
	auto itrEnd = my_payments.end();
	for (; itr != itrEnd; ++itr)//free the payments
		delete *itr;
}

int Buyer::MakingPayment() {//remove all the items that been ordered from the items and set a payment for each one base on the seller
	int sizeOrderItems = my_order.GetItems().getSize();
    if(!sizeOrderItems)
        return 0;
	auto itr = my_order.GetItems().GetItems().begin();
	auto itrEnd = my_order.GetItems().GetItems().end();
    int to_start = my_payments.size();//where to start search seller
    for (; itr != itrEnd; ++itr) {//iteration for each item
        int numOfPayments = my_payments.size();//num of payments exist
        bool to_continue = true;
		auto itrTemp = my_payments.begin();
		auto itrTempEnd = my_payments.end();
        Item *item = *itr;//get the first item
        for (; itrTemp!=itrTempEnd && to_continue; ++itrTemp) {//search the seller
            if (*(*itrTemp)->GetSeller() == item->GetSeller()) {//compare between the users to see if there a match
                to_continue = false;//no need to continue
                (**itrTemp) += item;//adding item to this payment
            }
        }
        if (to_continue) {//case need new payment
            Payment *newPayment = new Payment(*this, item->GetSeller(), item);
            my_payments.push_back(newPayment);
        }
		myItems.GetItems().remove(item);//remove item from the items
        }
    my_order.MakeEmpty();//empty the order
    return 1;
}

bool Buyer::AddingFeedback(const string &sellerUserName, const string &feedbackText)const {
	auto itr = my_payments.begin();
	auto itrEnd = my_payments.end();
	for (; itr != itrEnd; itr++) {//check first if the seller is one that the buyer actaully bought from him
		Seller *seller = (*itr)->GetSeller();
        if (seller->GetUserName() == sellerUserName ) {
            seller->GetAllFeedback().push_back(new FeedBack(*this, feedbackText));//add the feedback
            return true;
        }
    }
    return false;
}

const Buyer & Buyer::operator+=(Item *item) {//add item to the buyers items
	myItems.GetItems().push_back(item);
    return *this;
}

const Buyer & Buyer::operator>(const Buyer &other) const {//check who is bigger
	Buyer * temp =const_cast<Buyer *> (&other);
    return (myItems.getSum()) > (temp->GetItems().getSum()) ? *this : other;

}


void Buyer::showPayments()const
{
	if (my_payments.size() == 0)
		cout << "no payments\n";
	else
	{
		auto itr = my_payments.begin();
		auto itrEnd = my_payments.end();
		for (; itr != itrEnd; ++itr)
		{
			cout <<"buyer: "<<*((*itr)->getBuyer()) ;
			cout << "seller: " << *((*itr)->GetSeller()) ;
			(**itr).getItems().showItems();
			cout<<"total: " << (*itr)->GetAmount()<<endl;
		}
		cout << "------------------------\n";

	}
}