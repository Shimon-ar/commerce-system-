//
// Created by Shimon Arshavsky on 13/12/2019.
//

#include <iostream>
#include <string.h>
#include "User.h"
#include "Address.h"

using namespace std;


User::User(const string &user_name, const string &password, const Address &address): user_name(user_name),//initial user
                                                                                  password(password),
                                                                                  address(address) {}


User::~User() {
    
}

bool User::validUserName(const string & userName) {//check no space at username
  
	if (userName.size() > 0&&(userName.find(' ')))
		return true;
	else
		return false;
	
}

void User::SetAddress(const Address &address) {
    this->address = address;
}

bool User::SetUserName(const string& user_name) {
    if (!validUserName(user_name))//check invalid input
        return false;
   
    this->user_name = user_name;//allocate new one
    return true;
}

void User::SetPassword(const string& password) {
    
    this->password = password;
}

bool User::operator==(const User &other) {
    return ((this->user_name== other.user_name)  && (this->password==other.password));
}

const User& User::operator=(const User &other) {
    if(this != &other){
        this->SetPassword(other.password);
        this->SetAddress(other.address);
        this->SetUserName(other.user_name);
    }
    return *this;
}



