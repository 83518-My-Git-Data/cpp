#include <iostream>
using namespace std;

// HERE I HAVE USED THE DYNAMIC MEMORY TO SAVE MEMORY USAGE FOR EACH CLASS DIFFERENTLY.

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 30;
        month = 9;
        year = 2000;
    }
    void acceptDate()
    {
        cout<<endl;
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the month: ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date *birthdate;

public:
    Person()
    {
        
        birthdate = new Date(); // compulsory declared so follows composition
    }
    

    void acceptPerson()
    {
        cout<<endl;
        cout << "Enter name of Person:";
        cin>>name;
        cout << "Enter address of Person:";
        cin>> address;
        cout << "Enter birthdate of Person:";
        birthdate->acceptDate();
        cout << endl;
    }

    void printPersonDetails()
    {
        cout << "Personal Details of the Person: "<<endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;

        if (birthdate != NULL)
        {
            cout << "Birthdate: ";
            birthdate->displayDate();
        }
    }

    ~Person()
    {
        if (birthdate != NULL)
        {
            delete birthdate;
            birthdate = NULL;
        }
    }
};

class Employee
{
private:
    int id;
    double sal;
    string dept;
    Date *jdate;

public:
    Employee()
    {
        jdate = new Date(); // compulsory declared so follows composition
    }

    void acceptEmployee()
    {
        cout << "Enter empid of Employee - ";

        cin >> id;
        cout << "Enter Depatement of Employee - ";
        cin>>dept;
        cout << "Enter salary of Employee - ";

        cin >> sal;
        cout << "Enter Date of Joining of Employee - "<<endl;
        jdate->acceptDate();
    }

    void PrintEmployeeDetails()
    {
        cout <<endl<< "Personal details of employee: " << endl;
        
        cout << "Employee id: " << id << endl;
        cout << "Department of the Employee: " << dept << endl;
        
         if (jdate != NULL)
        {
           cout << "Joining Date: " << endl;
            jdate->displayDate();
        }

    }

    ~Employee()
    {
        if (jdate != NULL)
        {
            delete jdate;
            jdate = NULL;
        }
    }
};

int main()
{
    Employee e1;
    e1.acceptEmployee();
    e1.PrintEmployeeDetails();
    Person p1;
    p1.acceptPerson();
    p1.printPersonDetails();
   

    return 0;
}