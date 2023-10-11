#include <iostream>
#include <string>
#include "highInterestChecking.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double highInterestChecking::INTEREST_RATE = 0.05;
const double highInterestChecking::MIN_BALANCE = 5000.00;

highInterestChecking::highInterestChecking(string n, int acctNumber, double bal):noServiceChargeChecking(n,acctNumber,bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

highInterestChecking::highInterestChecking(string n, int acctNumber, double bal, double minBal, double intRate):
noServiceChargeChecking(n,acctNumber,bal)
{
	minimumBalance = minBal;
	interestRate = intRate;
}

double highInterestChecking::getInterestRate()
{
	return interestRate;
}

void highInterestChecking::setInterestRate(double intRate)
{
	interestRate = intRate;
}

void highInterestChecking::postInterest()
{
	double money;

	money = balance * interestRate;

	balance += money;
}

void highInterestChecking::createMonthlyStatement()
{
	postInterest();
}

void highInterestChecking::print()
{
	cout.setf(ios::fixed);
	cout << "High Interest Checking:     " << name << "    ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}