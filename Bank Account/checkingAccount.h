#ifndef H_checkingAccount
#define H_checkingAccount

#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

class checkingAccount: public bankAccount
{
public:

	checkingAccount(string n, int acctNumber, double bal);
	virtual void writeCheck(double amount) = 0;
};

#endif
