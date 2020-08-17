//
// Created by Shimon Arshavsky on 14/12/2019.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "FeedBack.h"
#include "Buyer.h"
#include <ctime>
using namespace std;


FeedBack::FeedBack(const Buyer& buyer,const string & text):BuyerName(buyer.GetUserName()),text(text),date(getDateAux()) {

    
}

FeedBack::~FeedBack() {
}

void FeedBack::SetText(const string & feedbackText) {
	
	text = feedbackText;
   
}
 const char *  FeedBack:: getDateAux()
{
	 time_t now = time(0);//initial the time and the buyer name that cannot be change from here
	 char* dt = ctime(&now);
	 return dt;
}

