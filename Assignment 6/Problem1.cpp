#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(): day(1),month(1),year(2024)
        {
            
        }   

        void acceptDate(){
            cout<<"Enter Day: ";
            cin>>day;
            cout<<"Enter Month: ";
            cin>>month;
            cout<<"Enter year: ";
            cin>>year;

        }
        void displayDate(){
            cout<<day<<"-"<<month<<"-"<<year<<endl;
        }
};  


class Person{
    private:
        string name;
        string address;
        Date *birDate;
    public:
        Person()
        {
            name = "";
            address = ""; 
            birDate = new Date;
        }    
        
        void acceptData(){
            cout<<"Enter the Person Name: ";
            cin>>name;
            cout<<"Enter Address :";
            cin>>address;
            cout<<"Enter Birth Date - "<<endl;
            birDate->acceptDate();
        }
        
        void displayData(){
            cout<<"The Details of the Person are: "<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"BirthDate : ";
            birDate->displayDate();
        }

        ~Person(){
            delete birDate;
            birDate = NULL;
        }

};

class Employee : public Person
    {
    private:
        int id;
        string name;
        double sal;
        string dept;
        Date *joinDate;

    public:
    Employee()
    {
        id = 0;
        sal = 10000;
        dept = "";
        joinDate = new Date;
    }

    void acceptData(){
        cout<<"Enter Employee Id: ";
        cin>>id;
        cout<<"Enter Employee Name: ";
        cin>>name;
        cout<<"Enter Salary: ";
        cin>>sal;
        cout<<"Enter Department : ";
        cin>>dept;
        cout<<"Enter the Joining Date - "<<endl;
        joinDate->acceptDate();

    }

    void diplayData(){
        cout<<"The Employee Details are: "<<endl;
        cout<<"Employee Id - "<<id<<endl;
        cout<<"Salary - "<<sal<<endl;
        cout<<"Department - "<<dept<<endl;
        cout<<"The Joining Date -";
        joinDate->displayDate();

    }

    ~Employee(){
        delete joinDate;
        joinDate = NULL;
    }

};


int main(){

    Person *ptr = new Employee();  //<- Upcasting 
    ptr->acceptData();   //<- this will point to the derived functions from the parent class.
    ptr->displayData();
    // Person p;         <- person object p created   
    // p.acceptData();   <- to accept the person details    
    // p.displayData();  <- to see the person details 
    // Employee e;       <- Employee object e created 
    // e.acceptData();   <- to accept the Employee details 
    // e.diplayData();   <- to display the Employee details
    return 0;
}