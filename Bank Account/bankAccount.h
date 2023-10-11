#ifndef H_bankAccount
#define H_bankAccount

#include <iostream>
#include <string>

using namespace std;

class bankAccount
{
protected:
	int accountNumber;
	string name;
	double balance;

public:

	bankAccount(string n = "", int acctNumber = 0, double bal = 0.0);
	int getAccountNumber();
	double getBalance();
	string getName();
	void setName(string n);
	virtual void withdraw(double amount);
	void deposit(double amount);
	virtual void createMonthlyStatement() = 0;
	virtual void print();
};

#endif