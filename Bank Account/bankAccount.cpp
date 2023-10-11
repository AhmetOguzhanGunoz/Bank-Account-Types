#include <iostream>
#include <string>
#include "bankAccount.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

bankAccount::bankAccount(string n, int acctNumber, double bal)
{
	name = n;
	accountNumber = acctNumber;
	balance = bal;
}

int bankAccount::getAccountNumber()
{
	return accountNumber;
}

double bankAccount::getBalance()
{
	return balance;
}

string bankAccount::getName()
{
	return name;
}

void bankAccount::setName(string n)
{
	name = n;
}

void bankAccount::withdraw(double amount)
{
	if(amount <= 0)
		cout << "Enter a valid value" << endl;
	else if (amount > balance)
	{
		cout << "Balance doesnt have entered value amount";
	}
	else
	{
		balance -= amount;
	}
}

void bankAccount::deposit(double amount)
{
	if(amount <= 0)
		cout << "Enter a valid value" << endl;
	else
		balance += amount;
}

void bankAccount::print()
{
	cout << "" << name << "ACCT # " << accountNumber << "Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}