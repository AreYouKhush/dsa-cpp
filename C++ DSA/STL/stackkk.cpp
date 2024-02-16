#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> s;

    s.push("hello");
    s.push("world");
    s.push("wide");

    cout<<"Top element: "<<s.top()<<endl;

    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Size of stack: "<<s.size()<<endl;

    cout<<"Empty or not: "<<s.empty()<<endl;
}