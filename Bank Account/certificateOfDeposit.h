#ifndef H_certificateOfDeposit
#define H_certificateOfDeposit

#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

class certificateOfDeposit: public bankAccount
{
private:
	static const double INTEREST_RATE;
	static const int NUMBER_OF_MATURITY_MONTHS;
	double interestRate;
	int maturityMonths;
	int cdMonth;

public:

	certificateOfDeposit(string n, int acctNumber, double bal);
	certificateOfDeposit(string n, int acctNumber, double bal, double intRate, int maturityMon);
	double getInterestRate();
	void setInterestRate(double rate);
	double getCurrentCDMonth();
	void setCurrentCDMonth(int month);
	double getMaturityMonths();
	void setMaturityMonths(int month);
	void postInterest();
	void withdraw(double amount);
	void withdraw();
	void createMonthlyStatement();
	void print();
};

#endif