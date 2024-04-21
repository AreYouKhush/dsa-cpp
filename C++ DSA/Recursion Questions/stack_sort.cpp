#include<bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s){
	
}

void fillStack(vector<int> v, stack<int>& s){
    for(auto it: v){
        s.push(it);
    }
}

int main(){
    stack<int> s;
    fillStack({2,1,3,4,2} , s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}