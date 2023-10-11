#include <iostream>
#include <string>
#include "noServiceChargeChecking.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double noServiceChargeChecking::MIN_BALANCE = 1000.00;
const double noServiceChargeChecking::INTEREST_RATE = 0.02;

noServiceChargeChecking::noServiceChargeChecking(string n, int acctNumber, double bal):checkingAccount(n,acctNumber,bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

noServiceChargeChecking::noServiceChargeChecking(string n, int acctNumber, double bal, double minBalance, double intRate):
checkingAccount(n,acctNumber,bal)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

double noServiceChargeChecking::getMinimumBalance()
{
	return minimumBalance;
}

void noServiceChargeChecking::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

bool noServiceChargeChecking::verifyMinimumumBalance(double amount)
{
	return ((balance - amount) >= minimumBalance);
}

void noServiceChargeChecking::writeCheck(double amount)
{
	if(verifyMinimumumBalance(amount))
		balance -= amount;
	else
		cout << "No Service Charge Checking: Balance can not be less then minimum value." << endl;
}

void noServiceChargeChecking::withdraw(double amount)
{
	if(verifyMinimumumBalance(amount))
		balance -= amount;
	else
		cout << "No Service Charge Checking: Balance can not be less then minimum value." << endl;
}

void noServiceChargeChecking::createMonthlyStatement()
{
	double money;

	money = balance * interestRate;

	balance += money;
}

void noServiceChargeChecking::print()
{
	cout.setf(ios::fixed);
	cout << "No Service Charge Checking: " << name << "      ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}