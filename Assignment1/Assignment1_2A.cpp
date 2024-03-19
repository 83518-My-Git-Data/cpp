#include<iostream>
using namespace std;

struct Date{

    int day;
    int month;
    int year;
};

void initDate(struct Date* date)
{
    date->day = 10;
    date->month=4;
    date->year =2014;
}

void acceptDate(struct Date* date)
{
    cout<<"Enter day: ";
    cin>> date->day;
    cout<<"Enter month: ";
    cin>> date->month;
    cout<<"Enter year: ";
    cin>> date->year;
}

void printDate(struct Date* date)
{
    cout<<"The Date Entered by you is ";
    cout<<date->day<<" : "<<date->month<<" : "<<date->year<<endl;

}

bool isLeapYear(struct Date* date)
{
    if(date->year%400 ==0 ||date->year%100 ==0||date->year%4 ==0)
    {
        cout<<endl<<"The Year you entered is a leap year"<<endl;
        return true;
    }
    else
    {
        cout<<endl<<"The Year you entered is not a leap year"<<endl;
        return false;

    }
}


int main()
{
    struct Date d1;
    initDate(&d1);
    acceptDate(&d1);
    printDate(&d1);
    isLeapYear(&d1);
    return 0;
}