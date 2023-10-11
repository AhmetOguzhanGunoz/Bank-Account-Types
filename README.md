# Bank Account Types
 Project is an example prototype of Bank Account Types under virtual function usage and inheritance theme. Base class has deposit() function.

CertificateOfDeposit Type = 
In Default(Interest Rate = 0.05, Does not allow withraw within 6 months) but these values can be changed when opening account, 
Does not allow withraw within positive number of months
Allow withdraw after positive number of months without verifying minimum balance, 
Allow withdraw as amount(amount can be all balance) after positive number of months
Balance increase related to interest rate

SavingsAccount Type = 
In Default(Interest Rate = 0.03) but this value can be changed when opening account
Allow withdraw without verifying minimum balance,
Allow withdraw as amount(amount can be all balance)
Balance increase related to interest rate

HighInterestSavings Type = 
In Default(Interest Rate = 0.05, Must have minimum balance = 2500) but these values can be changed when opening account,
Allow withdraw with verifying minimum balance,
Allow withdraw as amount(with verifying)
Balance increase related to interest rate

NoServiceChargeChecking = 
In Default(Interest Rate = 0.02, Must have minimum balance = 1000) but these values can be changed when opening account,
Allow withdraw with verifying minimum balance,
Allow withdraw as amount(with verifying)
Allow write checks with verifying minimum balance,
No charges for writing free checks,
No limit number for writing free checks,
Balance increase related to interest rate

HighInterestChecking Type = 
In Default(Interest Rate = 0.05, Must have minimum balance = 5000) but these values can be changed when opening account, 
Allow withdraw with verifying minimum balance,
Allow withdraw as amount(with verifying),
Allow write checks with verifying minimum balance,
No charges for writing free checks,
No limit number for writing free checks,
Balance increase related to interest rate

ServiceChargeChecking = 
In Default(Allow writing maximum 5 free checks monthly, writing check with 5 amount of check payment after written 5 check, monthly 10 amount of account payment) but these values can be changed when opening account,
Allow withdraw without verifying minimum balance,
Allow withdraw as amount(amount can be all balance)
Allow write checks without verifying minimum balance,
Charges for writing checks that exceed free number of checks,
Limit number for writing free checks,
Balance decrase related to monthly account payment
