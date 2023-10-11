#include <iostream>
#include <string>
#include "savingsAccount.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double savingsAccount::INTEREST_RATE = 0.03;

savingsAccount::savingsAccount(string n, int acctNumber, double bal):bankAccount(n,acctNumber,bal)
{
	interestRate = INTEREST_RATE;
}

savingsAccount::savingsAccount(string n, int acctNumber, double bal, double intRate):bankAccount(n,acctNumber,bal)
{
	interestRate = intRate;
}

double savingsAccount::getInterestRate()
{
	return interestRate;
}

void savingsAccount::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingsAccount::postInterest()
{
	double money;

	money = balance * interestRate;

	balance += money;

}

void savingsAccount::createMonthlyStatement()
{
	postInterest();
}

void savingsAccount::print()
{
	cout.setf(ios::fixed);
	cout << setprecision(3);
	cout << "Savings Account:            " << name << "      ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}



