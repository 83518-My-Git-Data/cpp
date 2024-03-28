#include <iostream>
using namespace std;

enum EAccountType
{
    SAVING = 1,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
private:
    int accno;
    double currentBalance;
    double withdrawAccount;

public:
    InsufficientFundsException(int accno, double currentBalance, double withdrawAccount)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAccount = withdrawAccount;
    }

    void displayInfo()
    {
        cout << "Accno: " << accno << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Withdraw Amount: " << withdrawAccount << endl;
    }
};

class Account
{
private:
    int accno;
    double balance;
    EAccountType eaType;

public:
    Account()
    {
        accno = 100;
        balance = 1000;
        eaType = SAVING;
    }

    Account(int accno, EAccountType eaType, double balance)
    {
        this->accno = accno;
        this->eaType = eaType;
        this->balance = balance;
    }

    int getAccno()
    {
        return accno;
    }

    void accept()
    {
        int num;
        cout << "Enter the Account number of the employee: ";
        cin >> accno;
        cout << "Enter the Balance of the employee: ";
        cin >> balance;
        cout << "Enter the account type: 1.SAVING 2.CURRENT 3.DMAT" << endl;

        cin >> num;
        if (num <= 0 || num > 3)
        {
            throw 1;
        }
        eaType = (EAccountType)num;
    }

    void display()
    {
        cout << "********************************************************" << endl;
        cout << "Account Number: ";
        cout << accno << endl;
        cout << "Balance: ";
        cout << balance << endl;
        cout << "Account Type: ";

        // int choice;

        switch (EAccountType(eaType))
        {
        case SAVING:
            cout << "SAVING" << endl;
            break;
        case CURRENT:
            cout << "CURRENT" << endl;
            break;
        case DMAT:
            cout << "DMAT" << endl;
            break;
        }
    }

    void deposit(double amount)
    {

        this->balance = this->balance + amount;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw InsufficientFundsException(this->accno, this->balance, amount);
        }
        this->balance = this->balance - amount;
    }
};

int main()
{
    int index = 0;
    int amtDeposit;
    int amtWithdraw;
    Account *acc[5];

    int choice;
    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Create Account: " << endl;
        cout << "2. Deposit into the account: " << endl;
        cout << "3. Withdraw from the account: " << endl;
        cout << "4. Display from the account: " << endl;

        cout << "Enter your choice - ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        try{
            acc[index] = new Account;
            acc[index]->accept();
            acc[index]->display();

            index++;
        }catch(int)
        {
            cout<<"Invalid account type option."<<endl;
        }
            break;

        case 2:

            cout << "Enter the Amount to Deposit: ";
            cin >> amtDeposit;
            cout << "Enter the Accno" << endl;
            int accno;
            cin >> accno;
            for (int i = 0; i < index; i++)
            {
                if (acc[i]->getAccno() == accno)
                {
                    acc[i]->deposit(amtDeposit);
                }
            }
            break;

        case 3:
            try
            {
                int acno;

                cout << "Enter the Amount to withdraw: ";
                cin >> amtWithdraw;

                cout << "Enter the Accno" << endl;
                cin >> acno;
                for (int i = 0; i < index; i++)
                {
                    if (acc[i]->getAccno() == acno)
                    {
                        acc[i]->withdraw(amtWithdraw);
                    }
                }
            }
            catch (InsufficientFundsException e)
            {
                e.displayInfo();
                cout << "Amount you are trying to withdraw is greater than the available balance!" << endl;
            }
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                acc[i]->display();
            }
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < index; i++)
    {
        delete acc[i];
    }
    return 0;
}