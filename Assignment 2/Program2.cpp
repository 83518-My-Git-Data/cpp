#include<iostream>
using namespace std;

class Tollbooth{  
    private:
        double amount;
        unsigned int carNum;  

    public:

        Tollbooth(){
            carNum = 0;
            amount = 0;
        }

        void payingCar(){
            carNum++;
            amount += 0.50;
           
        }   

        void noPayCar(){
            carNum++;
            
        }  

        void printOnConsole(){
            int payingCar = (amount/0.5);
            int noPayCar = carNum-payingCar;
            cout<<"The Total Paying Cars: "<<payingCar<<endl;
            cout<<"The Total Non-Paying Cars: "<<noPayCar<<endl;
            cout<<"The Total Cars Passed By : "<<carNum<<endl;
            cout<<"The Total Amount Collected: "<<amount<<endl;

        }
};

int main(){ 
    Tollbooth t;
    int choice;
    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Paying Car"<<endl;
        cout<<"2. Non-Paying Car"<<endl;
        cout<<"3. Display Summery"<<endl;
        cin>>choice;

        switch(choice){

            case 1:     cout<<"The car passed had paid the Amount!!!"<<endl;
                        t.payingCar();
                        break;
            case 2:     cout<<"The car passed has not paid the Amount!!!"<<endl;
                        t.noPayCar();
                        break;
            case 3:     cout<<"The Summery is:"<<endl;
                        t.printOnConsole();
                        break;            

        }
    } while(choice!=0);
    return 0;
}