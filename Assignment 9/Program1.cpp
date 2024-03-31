#include <iostream>
#include <vector>
using namespace std;

enum EAccountType {
    SAVING = 1,
    CURRENT,
    DMAT
};

class InSufficientFundsException {
private:
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InSufficientFundsException() {}

    InSufficientFundsException(int accno, double currentBalance, double withdrawAmount) {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
    }

    void display() {
        cout << "Insufficient Balance" << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Withdraw Attempt Amount: " << withdrawAmount << endl;
        cout << "Available Balance: " << currentBalance << endl;
    }
};

class Account {
private:
    const int accno;
    EAccountType accType;
    double balance;
    static int genAccNo;

public:
    Account() : accno(++genAccNo) {}

    Account(double balance, EAccountType accType) : accno(++genAccNo) {
        this->balance = balance;
        this->accType = accType;
    }

    void accept() {
        try {
            int choice;
            cout << "Enter Account Type: " << endl;
            cout << "Press 1 to Create a SAVING Account" << endl;
            cout << "Press 2 to Create a CURRENT Account" << endl;
            cout << "Press 3 to Create a DEMAT Account" << endl;
            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3)
                throw 1;
            else {
                accType = static_cast<EAccountType>(choice);
                balance = 0;
                cout << "The Account has been created!!" << endl;
            }
        } catch (int error) {
            cout << "Invalid Choice Entered!!" << endl;
            cout << "Transaction Failed!!" << endl;
        }
    }

    void display() {
        cout << "Account No: " << accno << endl;
        switch (accType) {
            case SAVING:
                cout << "Account Type: Saving" << endl;
                break;
            case CURRENT:
                cout << "Account Type: CURRENT" << endl;
                break;
            case DMAT:
                cout << "Account Type: DMAT" << endl;
                break;
            default:
                break;
        }
        cout << "The Available Balance is: " << balance << endl;
    }

    int getAccno() {
        return accno;
    }

    void setBalance(int balance) {
        this->balance = balance;
    }

    double getBalance() {
        return balance;
    }

    double withdraw(int withdraw) {
        if (withdraw > balance)
            throw InSufficientFundsException(accno, balance, withdraw);
        else
            this->balance = balance - withdraw;
        cout << "The Amount has been withdrawn" << endl;
        return balance;
    }

    double deposit(int deposit) {
        if (deposit < 0)
            throw 1;
        else
            this->balance = balance + deposit;
        cout << "The Amount has been deposited" << endl;
        return balance;
    }
};

int Account::genAccNo = 0;

int main() {
    vector<Account*> accounts; 
    int choice;

    do {
        cout << "0. Exit" << endl;
        cout << "1. Create An Account" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Display Accounts" << endl;
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Thank you for using our App!" << endl;
                break;
            case 1:
                if (accounts.size() < 5) {
                    accounts.push_back(new Account());
                    accounts.back()->accept();
                } else {
                    cout << "Maximum account limit reached. Cannot create more accounts." << endl;
                }
                break;
            case 2:
                try {
                    int accNo;
                    cout << "Enter Account No: ";
                    cin >> accNo;
                    for (Account* acc : accounts) {
                        if (acc->getAccno() == accNo) {
                            double withdraw;
                            cout << "Enter Amount to Withdraw: ";
                            cin >> withdraw;
                            acc->withdraw(withdraw);
                        }
                    }
                } catch (InSufficientFundsException& e) {
                    cout << "Transaction Failed!" << endl;
                    e.display();
                }
                break;
            case 3:
                try {
                    int accNo;
                    cout << "Enter Account No: ";
                    cin >> accNo;
                    for (Account* acc : accounts) {
                        if (acc->getAccno() == accNo) {
                            double deposit;
                            cout << "Enter Amount to Deposit: ";
                            cin >> deposit;
                            acc->deposit(deposit);
                        }
                    }
                } catch (int error) {
                    cout << "The Deposit Amount is Invalid" << endl;
                    cout << "Transaction Failed!" << endl;
                }
                break;
            case 4:
                cout << "Displaying all accounts:" << endl;
                for (Account* acc : accounts) {
                    acc->display();
                }
                break;
        }
    } while (choice != 0);

    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
