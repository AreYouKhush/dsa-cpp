#include<iostream>
#include<array>
using namespace std;

int main(){
    int basic[] = {1, 2, 3};
    
    array<int, 4> arr = {1, 2, 3, 4};

    cout<<arr.size()<<endl;
    cout<<arr.at(3)<<endl;
    cout<<arr.at(1)<<endl;
    cout<<arr.empty()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;

    for(int i:arr){
        cout<<i<<" ";
    }
}