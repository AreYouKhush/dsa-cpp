#include<iostream>
using namespace std;
class Distance
{
    int feet, inches;
    public:
    void correction()
    {
        while(inches>11)
        {
            inches = inches-12;
            feet = feet+1;
        }
    }
    void getdata()
    {
        cout<<"Enter Feets: ";
        cin>>feet;
        cout<<"Enter Inches: ";
        cin>>inches;
        correction();
    }
    void add(Distance d1, Distance d2)
    {
        feet = d1.feet + d2.feet;
        inches = d1.inches + d2.inches;
        correction();
    }
    void display()
    {
        cout<<feet<<" Feets And "<<inches<<" Inches.";
    }
};

int main()
{
    Distance d1, d2, d3;
    cout<<"Enter Distance 1: "<<endl;
    d1.getdata();
    d1.display();
    cout<<"\n\nEnter Distance 2: "<<endl;
    d2.getdata();
    d2.display();
    cout<<"\n\nAddition: "<<endl;
    d3.add(d1, d2);
    d3.display();
    return 0;
}