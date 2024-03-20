#include<iostream>
using namespace std;

class Box{
    
    private:
        int length;
        int width;
        int height;

    public:

    Box()
    {
        length = 10;
        width = 5;
        height = 5;
    }

    Box(int value){
        length = value;
        width = value;
        height = value;
    }

    Box(int length , int width, int height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    void acceptValues(){
        cout<<"Enter the length of the Box: ";
        cin>>length;
        cout<<"Enter the width of the Box: ";
        cin>>width;
        cout<<"Enter the height of the Box: ";
        cin>>height;
    }

    void calculateBoxVolume(){
        int volume = length*width*height;
        cout<<"The Volume of the Box is: "<<volume<<endl;
    }  
   

}; 


int main(){                        
    Box b;
    int value;
    int choice;
    
        do{
            cout<<"0. Exit"<<endl;
            cout<<"1. Volume with the default values"<<endl;
            cout<<"2. Volume with a same value for Length, width, height"<<endl;
            cout<<"0. Volume with the different values for Length, width, height"<<endl;
            cin>>choice;
            switch(choice){
                            
                case 1 :    b.calculateBoxVolume();
                            break;

                case 2:    {cout<<"Enter the value:";
                            cin>>value;
                            Box b1(value);
                            b1.calculateBoxVolume();
                            break; }       

                case 3:     b.acceptValues();
                            b.calculateBoxVolume();
                            break;

         
    }
         } while(choice!=0);

    return 0;
}