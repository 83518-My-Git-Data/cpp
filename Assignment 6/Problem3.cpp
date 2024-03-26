// Q3. Implement following classes. 
// Test all functionalities in main() of each created class. 
// Note that employee is inherited into manager and salesman.

#include <iostream>
using namespace std;

const int MAX_EMPLOYEES = 100; // Maximum number of employees

class Employee
{
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}
    virtual void accept()
    {
        cout << "Enter the Employee ID: ";
        cin >> id;
        cout << "Enter the Salary of Employee: ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Employee Id - " << id << endl;
        cout << "Employee Salary - " << salary << endl;
    }
    virtual ~Employee() {}
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
    Manager() : bonus(0.0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}
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
    ~Manager() {}
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
    Salesman() : commission(0.0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}
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
    ~Salesman() {}
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus), Salesman(id, salary, commission) {}
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
    Employee *employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;
    do
    {
        cout << "\nMenu\n";
        cout << "1. Create a new Manager\n";
        cout << "2. Create a new Salesman\n";
        cout << "3. Create a new SalesManager\n";
        cout << "4. Display all Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Manager *mgr = new Manager();
            mgr->accept();
            employees[employeeCount++] = mgr;
            break;
        }
        case 2:
        {
            Salesman *salesman = new Salesman();
            salesman->accept();
            employees[employeeCount++] = salesman;
            break;
        }
        case 3:
        {
            SalesManager *salesMgr = new SalesManager();
            salesMgr->accept();
            employees[employeeCount++] = salesMgr;
            break;
        }
        case 4:
        {
            for (int i = 0; i < employeeCount; i++)
            {
                employees[i]->display();
            }
            break;
        }
        case 5:
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    for (int i = 0; i < employeeCount; i++)
    {
        delete employees[i];
    }

    return 0;
}
