#include <iostream>
#include <string>
#include "checkingAccount.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

checkingAccount::checkingAccount(string n,int acctNumber, double bal):bankAccount(n,acctNumber,bal)
{
}