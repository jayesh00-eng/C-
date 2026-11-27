#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        if(amount > 0)
        {
            balance = balance + amount;
            cout << "Amount Deposited Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if(amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Withdrawn Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation not available." << endl;
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }
};


class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int no, string name, double bal, double rate)
    : BankAccount(no, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int no, string name, double bal, double limit)
    : BankAccount(no, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount)
    {
        if(amount > 0 && amount <= getBalance() + overdraftLimit)
        {
            BankAccount::withdraw(amount);

            if(amount > getBalance())
            {
                cout << "Overdraft Limit Used!" << endl;
            }
        }
        else
        {
            cout << "Overdraft Limit Exceeded!" << endl;
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};


class FixedDepositAccount : public BankAccount
{
    int term;

public:
    FixedDepositAccount(int no, string name, double bal, int months)
    : BankAccount(no, name, bal)
    {
        term = months;
    }

    void calculateInterest()
    {
        double interest = getBalance() * 7 * term / (100 * 12);
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};


int main()
{
    SavingsAccount s(101, "Jayesh", 10000, 5);
    CheckingAccount c(102, "Rahul", 5000, 2000);
    FixedDepositAccount f(103, "Amit", 20000, 12);

    BankAccount *ptr;

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Savings Account";
        cout << "\n2. Checking Account";
        cout << "\n3. Fixed Deposit Account";
        cout << "\n4. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                ptr = &s;

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Balance";
                cout << "\n4. Calculate Interest";
                cout << "\n5. Account Info";
                cout << "\nEnter Choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->deposit(amount);
                }
                else if(choice == 2)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->withdraw(amount);
                }
                else if(choice == 3)
                    cout << "Balance: " << ptr->getBalance();
                else if(choice == 4)
                    ptr->calculateInterest();
                else if(choice == 5)
                    ptr->displayAccountInfo();

                break;

            case 2:
                ptr = &c;

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Balance";
                cout << "\n4. Check Overdraft";
                cout << "\n5. Account Info";
                cout << "\nEnter Choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->deposit(amount);
                }
                else if(choice == 2)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->withdraw(amount);
                }
                else if(choice == 3)
                    cout << "Balance: " << ptr->getBalance();
                else if(choice == 4)
                    c.checkOverdraft();
                else if(choice == 5)
                    ptr->displayAccountInfo();

                break;

            case 3:
                ptr = &f;

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Balance";
                cout << "\n4. Calculate Interest";
                cout << "\n5. Account Info";
                cout << "\nEnter Choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->deposit(amount);
                }
                else if(choice == 2)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    ptr->withdraw(amount);
                }
                else if(choice == 3)
                    cout << "Balance: " << ptr->getBalance();
                else if(choice == 4)
                    ptr->calculateInterest();
                else if(choice == 5)
                    ptr->displayAccountInfo();

                break;

            case 4:
                cout << "\nThank You For Using Banking System!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    }while(choice != 4);

    return 0;
}

