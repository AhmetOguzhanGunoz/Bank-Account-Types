#ifndef H_highInterestChecking
#define H_highInterestChecking

#include <iostream>
#include <string>
#include "noServiceChargeChecking.h"

using namespace std;

class highInterestChecking: public noServiceChargeChecking
{
private:
	static const double INTEREST_RATE;	static const double MIN_BALANCE;public:	 highInterestChecking(string n, int acctNumber, double bal);
	 highInterestChecking(string n, int acctNumber, double bal, double minBal, double intRate);
	 double getInterestRate();
	 void setInterestRate(double intRate);
	 void postInterest();
	 void createMonthlyStatement();	 virtual void print();
};

#endif
