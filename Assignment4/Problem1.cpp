#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int size;
    int *ptr;

public:
    stack(int size)
    {
        this->size =size;
        top = -1;
        ptr = new int[size];
    }

    void push(int ele)
    {
        if (!isFull())
        {
            top++;
            ptr[top] = ele;
        }
        else
        {
            cout << "STACK OVERFLOW!" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
            top--;
        else
            cout << "Stack underflow" << endl;
    }
    void peek()
    {
        cout<< ptr[top]<< endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == (size - 1);
    }

    void print()
    {
        cout<<"The Elements entered by user are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack s(5);
    int choice;

    do
    {
        cout << "Enter Your choice: " << endl;
        cout << "1. Push an element in the stack: " << endl;
        cout << "2. Pop an Element from the stack: " << endl;
        cout << "3. Display the current element:  " << endl;
        cout << "4. Display all the stack elements:  " << endl;
        cout << "Type 0 to escape the menu." << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
        {
            int ele;
            cout << "Enter an element to insert in the stack: ";
            cin >> ele;
            s.push(ele);
            break;
        }

        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.peek();
            break;
        }
        case 4:
        {
            s.print();
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
