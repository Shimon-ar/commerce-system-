//
// Created by Shimon Arshavsky on 13/12/2019.
//

#ifndef COMMERS_PROJECT_USER_H
#define COMMERS_PROJECT_USER_H

#include  "Address.h"
#include <iostream>

class User {//base class of all kind of users in the system
protected:
    string user_name;
	string password;
    Address address;
	User(const string &user_name, const string &password, const Address &address);
	

public:

  
	User(const User & user) = delete;
    virtual ~User();

    inline const string & GetUserName() const { return user_name; }

    inline const string & GetPassword() const { return password; }

    inline const Address &GetAddress() const { return address; }

    inline bool SetUserName(const string &user_name);

    inline void SetPassword(const string & password);

    inline void SetAddress(const Address & address);

    static bool validUserName(const string &userName);//static functions to check invalid input

    bool operator==(const User &other);//operator bool == checking user name and password

    const User &operator=(const User &other);//copy all the user content

    friend ostream &operator<<(ostream &os, const User & other){//print user data
		if (typeid(os) == typeid(ofstream))
		{
			os << other.user_name << "\n" << other.password << "\n" << other.address;
		}
		else
        os << "User name: " << other.user_name  <<  "\n" << other.address<<endl;

        return os;
    }

    friend ostream &operator<<(ostream &os, const string &userName) {//print only the user name
        os << userName;
        return os;
    }

    operator const string&() const { return user_name;}//operator casting to the name of the user

};

#endif //COMMERS_PROJECT_USER_H
