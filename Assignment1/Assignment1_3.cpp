#include <iostream>
using namespace std;


class student
{
private:
    int rollno;
    string name;
    double marks;

public:
    void initStudent()
    {
        rollno = 83518;
        name = "Harish";
        marks = 70.80;
    }

    void acceptStudent()
    {
        cout << "Enter roll no: ";
        cin >> rollno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void printStudent()
    {
        cout << "Roll no: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    struct student s1;
    s1.initStudent();
    s1.acceptStudent();
    s1.printStudent();
}