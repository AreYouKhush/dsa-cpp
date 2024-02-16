#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int> deq(3,4);

    deq.push_back(1);
    deq.push_front(2);

    for(int i:deq){
        cout<<i<<" ";
    }cout<<endl;

    // deq.pop_back();
    // deq.pop_front();
    // for(int i:deq){
        // cout<<i<<" ";
    // }cout<<endl;

    cout<<"First index: "<<deq.at(1)<<endl;

    cout<<"Front: "<<deq.front()<<endl;

    cout<<"Back: "<<deq.back()<<endl;

    cout<<"Empty or not: "<<deq.empty()<<endl;

    cout<<"Before Erase: "<<deq.size()<<endl;
    deq.erase(deq.begin(), deq.begin() + 1);
    cout<<"After Erase: "<<deq.size()<<endl;

    for(int i:deq){
        cout<<i<<" ";
    }cout<<endl;
}