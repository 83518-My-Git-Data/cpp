#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        // cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        // cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        // cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        // cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        // cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        // cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        // cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        //  cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    // Employee *eptr = new Employee();
    // Employee *eptr = new Manager();
    // Employee *eptr = new Salesman();
    // Employee *eptr = new SalesManager();
    // eptr->accept(); // Late Binding
    // eptr->display();

    // delete eptr;
    // eptr = NULL;

    int choice;
    int index = 0;
    Employee *arr[10];
    int x = 0;
    int managerCount = 0;
    int salesmanCount = 0;
    int salesmanagerCount = 0;
    int Count = 0;
    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Accept Employee: " << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers " << endl;
        cout << "Enter your choice - ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            if (index < 10)
            {
                cout << "Enter the choice" << endl;
                cout << "1. Accept the Manager Details: " << endl;
                cout << "2. Accept the Salesman Details: " << endl;
                cout << "3. Accept the Salesmanager Details: " << endl;
                cin >> x;
                if (x == 1)
                {
                    arr[index] = new Manager;
                    arr[index]->accept();
                    index++;
                    managerCount++;
                }
                else if (x == 2)
                {
                    arr[index] = new Salesman;
                    arr[index]->accept();
                    index++;
                    salesmanCount++;
                }
                else
                {
                    arr[index] = new SalesManager;
                    arr[index]->accept();
                    index++;
                    salesmanagerCount++;
                }
            }

            break;

        case 2:
            cout << "DIsplay the count of all employees with respect to designation: " << endl;
            cout << "Display the count of managers: " << managerCount << endl;
            cout << "Display the count of Salesman: " << salesmanCount << endl;
            cout << "Display the count of SalesManager: " << salesmanagerCount << endl;
            break;
        case 3:
            for (int i = 0; i < index; i++)
            {
                cout << "Manager Details--" << endl;
                if (typeid(*arr[i]) == typeid(Manager))
                {

                    arr[i]->display();
                    cout << "**********************************************" << endl;
                }
            }
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                cout << "SalesMan Details--" << endl;
                if (typeid(*arr[i]) == typeid(Salesman))
                {

                    arr[i]->display();
                    cout << "**********************************************" << endl;
                }
            }
            break;

        case 5:
            for (int i = 0; i < index; i++)
            {
                cout << "SalesManager Details--" << endl;
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                    cout << "**********************************************" << endl;
                }
            }
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < index; i++)
        delete arr[i];
    return 0;
}

// int main1()
// {
//     // Employee obj;
//     // Manager obj;
//     // Salesman obj;
//     // SalesManager obj;
//     // obj.accept();
//     // obj.display();

// }