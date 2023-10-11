#ifndef H_serviceChargeChecking
#define H_serviceChargeChecking

#include <iostream>
#include <string>
#include "checkingAccount.h"

using namespace std;

class serviceChargeChecking: public checkingAccount
{
protected:
	double serviceChargeAccount;
	double serviceChargeCheck;
	int numberOfChecksWritten;

private:

	static const double ACCOUNT_SERVICE_CHARGE;
	static const int MAXIMUM_NUM_OF_CHECKS;
	static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;

public:

	serviceChargeChecking(string n, int acctNumber, double bal);
	serviceChargeChecking(string n, int acctNumber, double bal, double servChargeAmount, double servChargeCheck);
	double getServiceChargeAccount();
	void setServiceChargeAccount(double amount);
	double getServiceChargeChecks();
	void setServiceChargeChecks(double amount);
	int getNumberOfChecksWritten();
	void setNumberOfChecksWritten(int num);
	void postServiceCharge();
	void writeCheck(double amount);
	virtual void createMonthlyStatement();	virtual void print();
};

#endif