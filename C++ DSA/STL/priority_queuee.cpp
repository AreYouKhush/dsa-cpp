#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq; // by default max_heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    // 1. push()
    // 2. pop()
    // 3. top()
    // 4. empty()
    // 5. size()
    pq.push(1);
    pq.push(4);
    pq.push(6);
    pq.push(8);
    pq.push(2);
    pq.push(34);

    min_pq.push(1);
    min_pq.push(4);
    min_pq.push(6);
    min_pq.push(8);
    min_pq.push(2);
    min_pq.push(34);

    while(pq.size() != 0){
        int i = pq.top();
        pq.pop();
        cout<<i<<" ";
    }
}