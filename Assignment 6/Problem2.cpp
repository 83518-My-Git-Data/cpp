#include<iostream>
using namespace std;

class Product{
    private: 
        int id;
        string title;
        double price;

    public:
        virtual void accept(){
            cout<<"Enter Product Id: ";
            cin>>id;
            cout<<"Enter Product Title: ";
            cin>>title;
            cout<<"Enter Product Price: ";
            cin>>price;
        }

        virtual void display(){

            cout<<"Id:"<<id<<endl;
            cout<<"Title:"<<title<<endl;
            cout<<"Price:"<<price<<endl;

        }

        void setPrice(int x){
            if( x == 1)
                price = price * 0.9;
            else
                price = price* 0.95;
        }

        double getPrice(){
            return price;
        }
};

class Book : public Product {
    private:
        string author;

    public:

    void accept(){
        cout<<"Enter Author Name: ";
        cin>>author;
        Product::accept();
        Product::setPrice(1);


    }

    virtual void display(){
        cout<<"The Author is: "<<author<<endl;
        Product::display();
        cout<<"The price with 10 percent Discount on Book- "<< Product::getPrice()<<endl;
    } 


};

class Tape : public Product{
    private:

    string artist;

    public:

    void accept(){
        cout<<"Enter Artist Name: ";
        cin>>artist;
        Product::accept();
        Product::setPrice(2);

    }
    virtual void display(){
        cout<<"The Artist is: "<<artist<<endl;
        Product::display();
        cout<<"The price with 5 percent Discount on Tape- "<< Product::getPrice()<<endl;
    }
};

int main(){
    Product *arr[3];
    int choice;
    double Total;    
    int index=0;

    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. To Add a Book"<<endl;
        cout<<"2. To Add a Tape"<<endl;
        cout<<"3. To  Display Total Price of the Products in the Cart"<<endl;
        cout<<"4. To Display the details of all the products in the cart"<<endl;
        cout<<"Enter Choice- ";
        cin>>choice;

        switch(choice){
            case 1 : if(index<3)
                     {   
                        arr[index] = new Book;
                        arr[index]->accept();
                        index++;
                     }else
                        cout<<"Cart is Full"<<endl;
                      break;  

            case 2 :  if(index<3)
                     {   
                        arr[index] = new Tape;
                        arr[index]->accept();
                        index++;

                     }else
                        cout<<"Cart is Full"<<endl;
                     break;     

            case 3 :    for(int i=0; i<index; i++)
                            Total += arr[i]->getPrice();
                        cout<<"Total price of all the Products in the Cart :"<<Total<<endl;
                        break;
                        
            case 4 :    for(int i=0; i<index; i++)
                            arr[i]->display();
                        break;    

        }
    } while(choice!=0);


   for(int i=0; i<index; i++){
    delete arr[i];
   }

    return 0;
}