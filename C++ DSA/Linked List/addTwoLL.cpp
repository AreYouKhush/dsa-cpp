#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

Node<int>* reverseLL(Node<int>* head){
    Node<int>* temp = head;
    Node<int>* next = nullptr;
    Node<int>* prev = nullptr;
    while(temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    Node<int>* reverseFirst = reverseLL(first);
    Node<int>* reverseSecond = reverseLL(second);
    Node<int>* head = reverseFirst;
    Node<int>* LastPtrOfFirst;
    int carry = 0;
    while(reverseSecond){
        int tempSum = 0;
        tempSum = carry + reverseSecond->data + reverseFirst->data;
        carry = 0;
        if(tempSum > 9){
            reverseFirst->data = tempSum%10;
            carry = 1;
        }else{
            reverseFirst->data = tempSum;
        }
        if(reverseFirst){
            LastPtrOfFirst = reverseFirst;
        }
        reverseFirst = reverseFirst->next;
        reverseSecond = reverseSecond->next;
    }
    while(reverseFirst){
        int tempSum = 0;
        tempSum = carry + reverseFirst->data;
        carry = 0;
        if(tempSum > 9){
            reverseFirst->data = tempSum%10;
            carry = 1;
        }else{
            reverseFirst->data = tempSum;
        }
        if(reverseFirst){
            LastPtrOfFirst = reverseFirst;

        }
        reverseFirst = reverseFirst->next;
    }
    if(carry = 1){
        Node<int>* temp = new Node<int>(1);
        LastPtrOfFirst->next = temp;
    }
    return reverseLL(head);
}

Node<int>* convertArrToLL(vector<int> &arr){
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node<int>* temp = new Node<int>(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int> temp1 = {9,9,9,9,9,9,9};
    vector<int> temp2 = {9,9,9,9};
    Node<int>* first = convertArrToLL(temp1);
    Node<int>* second = convertArrToLL(temp2);
    Node<int>* sumOfLL = addTwoLists(first, second);
    
    while(sumOfLL){
        cout<<sumOfLL->data<<" ";
        sumOfLL=sumOfLL->next;
    }
}