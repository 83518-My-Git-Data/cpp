#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* date) {
    date->day = 30;
    date->month = 9;
    date->year = 2000;
}

void acceptDate(struct Date* date) {
    printf("Enter day: ");
    scanf("%d", &date->day);
    printf("Enter month:");
    scanf("%d", &date->month);
    printf("Enter year");
    scanf("%d", &date->year);
}

void printDate(struct Date* date) {
    printf("The Date Entered by you is %d : %d : %d\n", date->day, date->month, date->year);
}

int main() {
    struct Date d1;
    initDate(&d1);
    acceptDate(&d1);
    printDate(&d1);

    return 0;
}