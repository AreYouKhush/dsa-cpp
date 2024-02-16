#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> q;

    q.push("hello");
    q.push("world");
    q.push("wide");

    cout<<"Size before pop: "<<q.size()<<endl;

    cout<<"Front: "<<q.front()<<endl;
    q.pop();
    cout<<"Front: "<<q.front()<<endl;
    
    cout<<"Size after pop: "<<q.size()<<endl;
}