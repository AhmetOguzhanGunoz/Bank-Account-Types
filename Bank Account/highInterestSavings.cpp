#include <iostream>
#include <string>
#include "highInterestSavings.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double highInterestSavings::MINIMUM_BALANCE = 2500.00;
const double highInterestSavings::INTEREST_RATE = 0.05;

highInterestSavings::highInterestSavings(string n, int acctNumber, double bal):savingsAccount(n,acctNumber,bal)
{
	interestRate = INTEREST_RATE;
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavings::highInterestSavings(string n, int acctN, double balance, double intRate, double minBalance):
savingsAccount(n,acctN,balance)
{
	interestRate = intRate;
	minimumBalance = minBalance;
}

double highInterestSavings::getMinimumBalance()
{
	return minimumBalance;
}

bool highInterestSavings::verifyMinimumBalance(double amount)
{
	return ((balance - amount) >= minimumBalance);
}

void highInterestSavings::withdraw(double amount)
{
	if(verifyMinimumBalance(amount))
		balance -= amount;
	else
		cout << "\nHigh Interest Savings:  Balance can not be less then minimum value." << endl;
}

void highInterestSavings::print()
{
	cout.setf(ios::fixed);
	cout << "High Interest Savings:      " << name << "     ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}