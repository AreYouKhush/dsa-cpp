#include<iostream>
using namespace std;
class Time
{
    int hour, min, sec;
    public:
    void correction()
    {
        while(sec>59||min>59)
        {
            if(sec>59)
            {
                sec=sec-60;
                min=min+1;
            }
            if(min>59)
            {
                min=min-60;
                hour=hour+1;
            }
        }
    }
    void display()
    {
        cout<<"Time is : "<<hour<<" : "<<min<<" : "<<sec;
    }
    void gettime()
    {
        cout<<"Hours: ";
        cin>>hour;
        cout<<"Minutes: ";
        cin>>min;
        cout<<"Seconds: ";
        cin>>sec;
        correction();
        display();
    }
    void add(Time &t1, Time &t2)
    {
        hour=t1.hour+t2.hour;
        min=t1.min+t2.min;
        sec=t1.sec+t2.sec;
        correction();
        display();
    }
};

int main()
{
    Time t1, t2, t3;
    cout<<"TIME 1: "<<endl;
    t1.gettime();
    cout<<"\nTIME 2: "<<endl;
    t2.gettime();
    cout<<"\n\nTime after Addition: ";
    t3.add(t1, t2);
    return 0;
}