#include <bits/stdc++.h>
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
    Node(int x, Node* ptr){
        data = x;
        next = ptr;
    }
};

Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {
    Node* head = list1;
    Node* mover = head;
    Node* nodeToConnect = head;
    while(b >= 0){
        nodeToConnect = nodeToConnect->next;
        b--;
    }
    while(a > 1){
        mover = mover->next;
        a--;
    }
    mover->next = list2;
    while(mover->next){
        mover = mover->next;
    }
    while(nodeToConnect){
        mover->next = nodeToConnect;
        nodeToConnect = nodeToConnect->next;
        mover = mover->next;
    }
    return head;
}

int main(){
    vector<int> arr1 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> arr2 = {1000000,1000001,1000002,1000003,1000004,1000005,1000006};
    int a = 3, b =  5;
    Node* head1 = convertArrToLL(arr1);
    Node* head2 = convertArrToLL(arr2);
    Node* mergedHead = mergeInBetween(head1, a, b, head2);
    while(mergedHead){
        cout<<mergedHead->data<<" ";
        mergedHead = mergedHead->next;
    }
    
}