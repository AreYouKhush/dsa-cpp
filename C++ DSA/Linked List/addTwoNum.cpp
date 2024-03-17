//Linked list is already in reverse order
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int temp = l1->val + l2->val;
    int carry = 0;
    if(temp > 9){
        carry = 1;
        temp = temp - 10;
    } 
    ListNode* head = new ListNode(temp);
    ListNode* mover = head;
    ListNode* num1 = l1->next;
    ListNode* num2 = l2->next;
    while(carry == 1 || num1 || num2){
        int d1 = num1 ? num1->val : 0;
        int d2 = num2 ? num2->val : 0;
        temp = d1 + d2 + carry;
        carry = 0;
        if(temp > 9){
            carry = 1;
            temp = temp - 10;
        }
        ListNode* t = new ListNode(temp);
        mover->next = t;
        mover = mover->next;
        if(num1) num1 = num1->next;
        if(num2) num2 = num2->next;
    }
    if(carry == 1){
        ListNode* t = new ListNode(1);
        mover->next = t;
        mover = mover->next;
    }
    return head;
}

ListNode* createLL(vector<int>& nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode* mover = head;
    for(int i = 1; i < nums.size(); i++){
        ListNode* temp = new ListNode(nums[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> l1 = {9,9,9,9,9,9,9};
    vector<int> l2 = {9,9,9,9};
    ListNode* L1 = createLL(l1);
    ListNode* L2 = createLL(l2);
    ListNode* ans = addTwoNumbers(L1, L2);
    printLL(L1);
    printLL(L2);
    printLL(ans);
}