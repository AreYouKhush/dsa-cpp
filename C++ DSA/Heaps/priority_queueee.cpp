#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(4);
    pq.push(6);
    pq.push(7);
    pq.push(2);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
}