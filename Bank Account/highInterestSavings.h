#ifndef H_highInterestSavings
#define H_highInterestSavings

#include <iostream>
#include <string>
#include "savingsAccount.h"

using namespace std;

class highInterestSavings: public savingsAccount
{
protected:
	double minimumBalance;

private:

	static const double MINIMUM_BALANCE; 
	static const double INTEREST_RATE; 

public:

	highInterestSavings(string n, int acctNumber, double bal);
	highInterestSavings(string n, int acctN, double balance, double intRate, double minBalance);
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void withdraw(double amount);
	virtual void print();
};

#endif