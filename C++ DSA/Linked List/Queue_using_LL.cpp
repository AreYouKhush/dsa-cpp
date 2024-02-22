#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

struct Queue {
  Node* front;
  Node* rear;
  
  Queue() {
    front = rear = NULL;
  }

  void push(int a){
    Node* newNode = new Node(a);
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }else if(front->next == NULL){
        front->next = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
  }

  int pop(){
    if(front == NULL){
        return -1;
    }else if(front->next == NULL){
        int ans = front->data;
        front = NULL;
        rear = NULL;
        return ans;
    }else{
        int ans = front->data;
        front = front->next;
        return ans;
    }
  }

  void display(){
    Node* temp = front;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
  }
};

int main(){
    Queue q;
    q.push(6);
    q.push(4);
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
}