#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
        Queue(){
            
        }
        void enQueue(int val) {
            // Implement the enqueue() function.
            s1.push(val);
        }
        void swap(stack<int> &a, stack<int> &b){
            while(a.size()){
                b.push(a.top());
                a.pop();
            }
        }
        int deQueue() {
            // Implement the dequeue() function.
            if(s1.size() == 0){
                return -1;
            }
            swap(s1, s2);
            int ans = s2.top();
            s2.pop();
            swap(s2, s1);
            return ans;
        }

        int peek() {
            // Implement the peek() function here.
            if(s1.size() == 0){
                return -1;
            }
            swap(s1, s2);
            int ans = s2.top();
            swap(s2, s1);
            return ans;
        }

        bool isEmpty() {
            // Implement the isEmpty() function here.
            if(s1.size() == 0){
                return 1;
            }
            return 0;
        }

        void display() {
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            while(s2.size()){
                cout<<s2.top();
                s2.pop();
            }
        }
};

int main(){
    Queue q1;
    q1.enQueue(5);
    q1.enQueue(9);
    q1.enQueue(2);
    q1.enQueue(5);
    q1.enQueue(3);
    q1.enQueue(0);
    cout<<q1.peek();
}