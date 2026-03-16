#include <iostream>

using namespace std;

class BankAccount 
{
private:
    char accountNumber[20];
    double balance;
    char ownerName[50];

public:

    void setupAccount(const char* name, const char* accNum, double initialBalance) 
	{
        int i = 0;
        while (name[i] != '\0' && i < 49) 
		{
            ownerName[i] = name[i];
            i++;
        }
        ownerName[i] = '\0';

        i = 0;
        while (accNum[i] != '\0' && i < 19) {
            accountNumber[i] = accNum[i];
            i++;
        }
        accountNumber[i] = '\0';

        balance = initialBalance;
    }

  
    void credit(double amount) 
	{
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    void debit(double amount) 
	{
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid amount or Insufficient Balance!" << endl;
        }
    }

    void displayBalance() 
	{
        cout << "\n--- Account Details ---" << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "A/C No: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() 
{
    BankAccount myAcc;

    myAcc.setupAccount("Rahul_Kumar", "SAV12345", 500.0);
    
    myAcc.displayBalance();

    cout << "Action: Crediting $200..." << endl;
    myAcc.credit(200.0);

    cout << "Action: Debiting $100..." << endl;
    myAcc.debit(100.0);

    cout << "Action: Attempting to debit $1000..." << endl;
    myAcc.debit(1000.0);

    myAcc.displayBalance();

    return 0;
}

