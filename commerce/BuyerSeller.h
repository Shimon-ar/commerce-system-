//
// Created by Shimon Arshavsky on 11/01/2020.
//

#ifndef COMMERS_PROJECT_BUYERSELLER_H
#define COMMERS_PROJECT_BUYERSELLER_H

#include "User.h"
#include "Buyer.h"
#include "Seller.h"

class BuyerSeller :public Seller , public Buyer{// nothing new in the class just all the attributes from the seller and the buyer
public:
    BuyerSeller(const string &user_name, const string password, const Address &address):User(user_name,password, address) , Seller(user_name, password, address) , Buyer(user_name, password, address){}//user inital once from here
    BuyerSeller(const BuyerSeller& other):User(other.GetUserName(), other.GetPassword(), other.GetAddress()),Seller(other),Buyer(other){}


};

#endif //COMMERS_PROJECT_BUYERSELLER_H
