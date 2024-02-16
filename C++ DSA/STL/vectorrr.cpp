#include<iostream>
#include<vector>
using namespace std;

int main(){

    // vector<int> vec;
    //or
    vector<int> vec(5, 4);      //here the size of vector is 5 and all the values are initialized with 4!!!

    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> last(vec);

    for(int i:last){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"Capacity: "<<vec.capacity()<<endl;

    vec.push_back(2);
    cout<<"Capacity: "<<vec.capacity()<<endl;

    vec.push_back(1);
    cout<<"Capacity: "<<vec.capacity()<<endl;

    vec.push_back(3);
    cout<<"Capacity: "<<vec.capacity()<<endl;

    cout<<"Size: "<<vec.size()<<endl;

    cout<<"Element at 2nd index: "<<vec.at(2)<<endl;

    cout<<"Element in Front: "<<vec.front()<<endl;
    cout<<"Element in Back: "<<vec.back()<<endl;

    cout<<"Before pop: ";
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
    vec.pop_back();

    cout<<"After pop: ";
    for(int i:vec){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"After pop Size changes: "<<vec.size()<<endl;
    cout<<"After pop Capacity does not change: "<<vec.capacity()<<endl;

    cout<<"Before Clear Size: "<<vec.size()<<endl;
    vec.clear();
    cout<<"After Clear Size: "<<vec.size()<<endl;


}