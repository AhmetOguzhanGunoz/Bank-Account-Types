#include <iostream>
#include <string>
#include "certificateOfDeposit.h"
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const double certificateOfDeposit::INTEREST_RATE = 0.05;
const int certificateOfDeposit::NUMBER_OF_MATURITY_MONTHS = 6;

certificateOfDeposit::certificateOfDeposit(string n, int acctNumber, double bal)
	:bankAccount(n,acctNumber,bal)
{
	interestRate = INTEREST_RATE;
	maturityMonths = NUMBER_OF_MATURITY_MONTHS;
	cdMonth = 0;
}

certificateOfDeposit::certificateOfDeposit(string n, int acctNumber, double bal,
		double intRate, int maturityMon):bankAccount(n,acctNumber,bal)
{
	interestRate = intRate;	
	maturityMonths = maturityMon;
	cdMonth = 0;
}

double certificateOfDeposit::getInterestRate()
{
	return interestRate;
}

void certificateOfDeposit::setInterestRate(double rate)
{
	interestRate = rate;
}

double certificateOfDeposit::getCurrentCDMonth()
{
	return cdMonth;
}

void certificateOfDeposit::setCurrentCDMonth(int month)
{
	cdMonth = month;
}

double certificateOfDeposit::getMaturityMonths()
{
	return maturityMonths;
}

void certificateOfDeposit::setMaturityMonths(int month)
{
	maturityMonths = month;
}

void certificateOfDeposit::postInterest()
{
	double money;

	money = balance * interestRate;

	balance += money;

}

void certificateOfDeposit::withdraw(double amount)
{
	if (cdMonth < NUMBER_OF_MATURITY_MONTHS)
	{
		cout << "\nCertificate of Deposit: Cant withdraw money before 6 moths" << endl;
	}
	else if (amount > balance)
	{
		cout << "Balance does not have entered value amount";
	}
	else
	{
		balance -= amount;
	}
}

void certificateOfDeposit::withdraw()
{
	if(cdMonth < NUMBER_OF_MATURITY_MONTHS)
		cout << "\nCertificate of Deposit: Cant withdraw money before 6 moths" << endl;
	else
		balance = 0;
}

void certificateOfDeposit::createMonthlyStatement()
{
	postInterest();
	cdMonth++;
}

void certificateOfDeposit::print()
{
	cout.setf(ios::fixed);
	cout << "Certificate of Deposit:     " << name << "     ACCT # " << accountNumber << "     Balance: " << balance;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L" \x20ba\n");
	_setmode(_fileno(stdout), _O_TEXT);
}