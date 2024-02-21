#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

class Stack{
    //Write your code here
    Node* ll = new Node();
    int size = 0;
    public:
    Stack(){
        //Write your code here
        size = 0;
    }

    int getSize(){
        //Write your code here
        return size;
    }

    bool isEmpty(){
        //Write your code here
        return size == 0;
    }

    void push(int data){
        //Write your code here
        Node* temp = ll;
        if(temp -> data == 0){
            temp -> data = data;
        }else{
            while(temp->next){
                temp = temp->next;
            }
            Node* newNode = new Node(data);
            temp->next = newNode;
        }
        size++;
    }

    void pop(){
        //Write your code here
        if(ll->next == NULL){
            size = 0;
            ll->data = 0;
            ll->next = NULL;
            return;
        }
        Node* temp = ll;
        while(temp->next->next){
            temp = temp->next;
        }
        temp->next = NULL;
        size--;
    }

    int getTop(){
        //Write your code here
        if(size == 0){
            return -1;
        }else{
            Node* temp = ll;
            while(temp->next){
                temp = temp->next;
            }
            return temp->data;
        }
    }
};

int main(){
    Stack s1;
    s1.push(2);
    s1.pop();
    cout<<s1.getTop();
    return 0;
}