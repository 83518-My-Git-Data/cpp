#include <iostream>
using namespace std;

class Time{
    private: 
        int h;
        int m;
        int s;

    public:

        Time():Time(h, m, s)
        {
            h = 23;
            m = 59;
            s = 59;
        }    

        Time(int h, int m, int s){
            this->h = h;
            this->m = m;
            this->s = s;
        }

        void printTime(){
            cout<<"The time is - "<<endl;
            cout<<"The Hour    : "<<h<<endl;
            cout<<"The Minutes : "<<m<<endl;
            cout<<"The Seconds : "<<s<<endl;
        }

        void setHour(int h){
            this->h = h;
        }

        int getHour(){
            return h;
        }

        void setMinute(int m){
            this->m = m;
        }
        
        int getMinute(){
            return m;
        }

        void setSeconds(int s){
            this->s = s;
        }
        
        int getSeconds(){
            return s;
        }

};

int main(){
    Time* timeptr1 = new Time();
    Time* timePtr2 = new Time(15, 35, 54);

    cout<<"Hour   : "<<timeptr1->getHour()<<endl;
    cout<<"Minute : "<<timeptr1->getMinute()<<endl;
    cout<<"Seconds: "<<timeptr1->getSeconds()<<endl;

    timePtr2->printTime();

    timePtr2->setHour(17);
    timePtr2->setMinute(24);
    timePtr2->setSeconds(34);

    timePtr2->printTime();

    delete timeptr1;
    delete timePtr2;

    timeptr1 = NULL;
    timePtr2 = NULL;

    return 0;

}