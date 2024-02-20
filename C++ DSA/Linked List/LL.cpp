#include <bits/stdc++.h>
using namespace std;

// Using Str4uct
// struct Node{
//     public:
//     int data;
//     Node* next;
//     Node(){
//         data = 0;
//         next = nullptr;
//     }
//     Node(int x){
//         data = x;
//         next = nullptr;
//     }
//     Node(int x, Node* ptr){
//         data = x;
//         next = ptr;
//     }
// };

//using Class
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

Node* middleNode(Node* head) {
        int count = 0;
        Node* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        int mid = ceil(count/2);
        cout<<count<<" "<<mid<<endl;
        count = 0;
        temp = head;
        while(temp){
            count++;
            cout<<count<<" ";
            if(count == mid){
                head = temp;
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

int main(){
    vector<int> arr = {2,5,7,8,6,0,7};
    Node* head = convertArrToLL(arr);
    Node* temp = middleNode(head);
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}