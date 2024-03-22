#include <iostream>
using namespace std;

class Cylinder
{
    double radius;
    double height;
    static const double pi;

public:
    Cylinder()
    {
        radius = 10.00;
        height = 10.00;
    }

    Cylinder(double radius, double height): radius(radius), height(height)
    {
    }

    double getRadius()
    {
        return radius;
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }
    double getHeight()
    {
        return height;
    }

    void setHeight(double height)
    {
        this->height = height;
    }

    void printVolume()
    {

        cout<<"volume of Cylinder is : "<<pi * radius * radius * height<<endl;
    }
};

const double Cylinder::pi =3.14;
int main()
{

    Cylinder c1;
    Cylinder c2(5,5);
    c1.printVolume();
    c2.printVolume();
    c1.setRadius(2);
    c2.setHeight(7);
    cout<<"Radius of c1 Cylinder is set to : "<<c1.getRadius()<<endl;
    cout<<"Height of c2 Cylinder is set to : "<<c2.getHeight()<<endl;
    c1.printVolume();
    c2.printVolume();

}