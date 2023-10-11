#include <iostream>
#include <string>
#include "serviceChargeChecking.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double serviceChargeChecking::ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeChecking::MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeChecking::SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;

serviceChargeChecking::serviceChargeChecking(string n, int acctNumber, double bal):checkingAccount(n,acctNumber,bal)
{
	serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
	serviceChargeCheck = SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
	numberOfChecksWritten = 0;
}

serviceChargeChecking::serviceChargeChecking(string n, int acctNumber, double bal, double servChargeAmount,
	double servChargeCheck):checkingAccount(n,acctNumber,bal)
{
	serviceChargeAccount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
}

double serviceChargeChecking::getServiceChargeAccount()
{
	return serviceChargeAccount;
}

void serviceChargeChecking::setServiceChargeAccount(double amount)
{
	serviceChargeAccount = amount;
}

double serviceChargeChecking::getServiceChargeChecks()
{
	return serviceChargeCheck;
}

void serviceChargeChecking::setServiceChargeChecks(double amount)
{
	serviceChargeCheck = amount;
}

int serviceChargeChecking::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

void serviceChargeChecking::setNumberOfChecksWritten(int num)
{
	numberOfChecksWritten = num;
}

void serviceChargeChecking::postServiceCharge()
{
	balance -= serviceChargeAccount;
}

void serviceChargeChecking::writeCheck(double amount)
{
	numberOfChecksWritten++;

	if (numberOfChecksWritten > MAXIMUM_NUM_OF_CHECKS)
	{
		int tempbalance = balance - ((numberOfChecksWritten - MAXIMUM_NUM_OF_CHECKS) * serviceChargeCheck) - amount;
		if (tempbalance < 0)
		{
			cout << "Balance does not have enough amount value to write check with specified amount " << endl;;
		}
		else
		{
			balance -= ((numberOfChecksWritten - MAXIMUM_NUM_OF_CHECKS) * serviceChargeCheck);
		}
	}
	else
	{
		if (amount <= 0)
		{
			cout << "Enter a valid value" << endl;
		}
		else if (amount > balance)
		{
			cout << "Balance does not have entered value amount" << endl;
		}
		else
		{
			balance -= amount;
		}
	}
}

void serviceChargeChecking::createMonthlyStatement()
{
	postServiceCharge();
	setNumberOfChecksWritten(0);
}

void serviceChargeChecking::print()
{
	cout.setf(ios::fixed);
	cout << "Service Charge Checking:    " << name << "      ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}