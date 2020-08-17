//
// Created by Shimon Arshavsky on 14/12/2019.
//
#pragma warning (disable:4996)
#ifndef COMMERS_PROJECT_FEEDBACK_H
#define COMMERS_PROJECT_FEEDBACK_H
#include <string>
#include <iostream>
using namespace std;
class Buyer;

class FeedBack{
private:
    const string date;//cannot be change from here
	const string BuyerName;//cannot be change from here
	string text;
	const char * getDateAux();
public:
    FeedBack(const Buyer& buyer , const string & text );
    FeedBack(const FeedBack& other) = delete;
    ~FeedBack();
	inline const string& getDate()const {return date; }
	inline const string& getText()const { return text; }
	inline const string& getBuyerName()const { return BuyerName; }
    void SetText(const string & feedbackText);
	friend ostream&operator<<(ostream& os, const FeedBack& other){//print feedback
        os<<"Date: "<<other.date<<"Buyer name: "<<other.BuyerName<<"\nText: "<<other.text;
        return os;
	}
};

#endif //COMMERS_PROJECT_FEEDBACK_H
