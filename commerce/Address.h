//
// Created by Shimon Arshavsky on 19/12/2019.
//
#pragma warning (disable:4996)

#ifndef COMMERS_PROJECT_ADDRESS_H
#define COMMERS_PROJECT_ADDRESS_H
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Address {
protected:
    string state;
	string city;
	string street;
    int num;
public:
    Address(const string & state, const string & city, const string & street, int num) : state(state),
                                                                                city(city),
                                                                                street(street), num(num) {}

    Address(const Address &other):state(other.state),city(other.city),street(other.city),num(other.num) {
       
    }

    ~Address() {
        
    }

    inline const string& getCity() const { return city; }

    inline const string& getState() const { return state; }

    inline const string& getStreet() const { return street; }

    inline int getNum() const { return num; }

    inline void setCity(const string& city) {
        
		this->city = city;
    }

    inline void setState(const string& state) {
        
		this->state = state;
    }

    inline void setStreet(const string&street) {  this->street = street; }

    inline void setNum(int num) { this->num = num; }

    friend ostream &operator<<(ostream &os, const Address &other) {
		if (typeid(os) == typeid(ofstream))
		{
			os << other.state << "\n" << other.city << "\n" <<
				other.street << "\n" << other.num << "\n";
		}
		else
			os << "State: " << other.state << "   City: " << other.city << "   Street: " <<
			other.street << "   Number: " << other.num << "\n";
        return os;
    }

    const Address &operator=(const Address &other) {
        if (this != &other) {
            this->setCity(other.city);
            this->setState(other.state);
            this->setStreet(other.street);
            this->setNum(other.num);
        }
        return *this;
    }
};

#endif //COMMERS_PROJECT_ADDRESS_H
