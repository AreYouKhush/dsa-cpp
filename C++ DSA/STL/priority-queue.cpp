#include<iostream>
#include<queue>
using namespace std;

int main(){
    //max-heap
    priority_queue<int> maxi;

    //min-heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(4);
    maxi.push(3);
    maxi.push(9);
    maxi.push(2);

    cout<<"Size of Max-heap: "<<maxi.size()<<endl;

    int n = maxi.size();

    for(int i = 0; i < n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    cout<<"Size: "<<maxi.size()<<endl;


    mini.push(4);
    mini.push(3);
    mini.push(9);
    mini.push(2);

    cout<<"Size of Min-heap: "<<mini.size()<<endl;

    n = mini.size();

    for(int i = 0; i < n; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    cout<<"Size: "<<mini.size()<<endl;

    cout<<"Empty or not: "<<mini.empty()<<endl;
}