//
// Created by Shimon Arshavsky on 13/12/2019.
//


#include <iostream>
#include <string.h>
#include "Item.h"
#include "Seller.h"
#include "User.h"

using namespace std;

int Item::id_num = 1;

Item::Item(const string &item_name, int price,Seller* seller, Item::Category type_item) ://initial
        seller(seller), price(price), type_item(type_item), id_item(id_num++),item_name(item_name){
}


Item::~Item() {
    
}

