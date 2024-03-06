#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int x){
        data = x;
        next = nullptr;
    }
    Node(int x, Node* p){
        data = x;
        next = p;
    }
};

Node* reverseLL(Node* head){
    Node* prevNode = NULL;
    Node* current = head;
    while(current){
        Node* temp = current->next;
        current->next = prevNode;
        prevNode = current;
        current = temp;
    }
    return prevNode;
}

Node* reverseLLRecursion(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLLRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9};

    Node* head = new Node(vec[0]);
    Node* mover = head;
    for(int i = 1; i < vec.size(); i++){
        Node* temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    // head = reverseLL(head);
    head = reverseLLRecursion(head);
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}