#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val){
        this->val = val; this->next = nullptr;
    }
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* tempHead = new ListNode();
    tempHead->next = head;
    int sum = INT_MAX;
    ListNode* start = tempHead;
    ListNode* currentNode = start->next;
    while(start && currentNode){
        sum = currentNode->val;
        currentNode = currentNode->next;
        while(currentNode){
            if(sum == 0){
                break;
            }else{
                sum += currentNode->val;
                currentNode = currentNode->next;
            }
        }
        if(sum != 0){
            start = start->next;
            currentNode = start->next;
        }else{
            start->next = currentNode;
        }
    }
    return tempHead->next;
}

int main(){
    vector<int> vec{-4, -6, 5, 1, 4};
    ListNode* head = new ListNode(vec[0]);
    ListNode* mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* newNode = new ListNode(vec[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    ListNode* zeroSumRemoved = removeZeroSumSublists(head);
    cout<<"Linked with zero sum consecutive nodes removes: "<<endl;
    while(zeroSumRemoved){
        cout<<zeroSumRemoved->val<<" ";
        zeroSumRemoved = zeroSumRemoved->next;
    }
}