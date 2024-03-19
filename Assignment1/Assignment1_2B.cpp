#include<iostream>
using namespace std;


class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(20), month(5), year(1999) {}

    void initDate() {
        day = 20;
        month = 5;
        year = 1999;
    }

    void acceptDate() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void printDate() {
        cout << "The Date Entered by you is " << day << " : " << month << " : " << year << endl;
    }

    bool isLeapYear() {
        if (year % 400 == 0 || year % 100 == 0 || year % 4 == 0) {
            cout << endl << "The Year you entered is a leap year" << endl;
            return true;
        } else {
            cout << endl << "The Year you entered is not a leap year" << endl;
            return false;
        }
    }
};

int main() {
    Date d1;
    d1.initDate();
    d1.acceptDate();
    d1.printDate();
    d1.isLeapYear();

    return 0;
}