#ifndef H_noServiceChargeChecking
#define H_noServiceChargeChecking

#include <iostream>
#include <string>
#include "checkingAccount.h"

using namespace std;


class noServiceChargeChecking: public checkingAccount
{
private:

	static const double MIN_BALANCE;
	static const double INTEREST_RATE;

protected:

	double minimumBalance;
	double interestRate;

public:

	noServiceChargeChecking(string n, int acctNumber, double bal);
	noServiceChargeChecking(string n, int acctNumber, double bal, double minBalance, double intRate);
	double getMinimumBalance();
	void setMinimumBalance(double minBalance);
	bool verifyMinimumumBalance(double amount);
	void writeCheck(double amount);
	void withdraw(double amount);
	virtual void createMonthlyStatement();	virtual void print();
};

#endif