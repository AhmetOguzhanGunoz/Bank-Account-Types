#ifndef H_savingsAccount
#define H_savingsAccount

#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

class savingsAccount: public bankAccount
{
private:
	static const double INTEREST_RATE;

protected:
	double interestRate;

public:
	savingsAccount(string n, int acctNumber, double bal);
	savingsAccount(string n, int acctNumber, double bal, double intRate);
	double getInterestRate();
	void setInterestRate(double rate);
	void postInterest();
	virtual void createMonthlyStatement();
	virtual void print();
};

#endif

