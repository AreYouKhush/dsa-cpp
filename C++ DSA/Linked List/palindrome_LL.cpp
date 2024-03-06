#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if(!head || !head->next){
        return true;
    }
    int sum = 0;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* firsthalf;
    ListNode* secondHalf;
    ListNode* prev = NULL;
    ListNode* current = head;
    while(current->next != slow->next){
        ListNode* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    firsthalf = prev;
    if(fast == NULL){
        secondHalf = slow;
    }else{
        secondHalf = slow->next;
    }
    if(firsthalf->next && secondHalf->next){
        while(firsthalf && secondHalf){
            if(firsthalf->val != secondHalf->val){
                return false;
            }
            cout<<firsthalf->val<<" "<<secondHalf->val<<endl;
            firsthalf = firsthalf->next;
            secondHalf = secondHalf->next;
        }
    }else{
        if(firsthalf->val != secondHalf->val){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> vec{0,2,2,1};
    ListNode* head = new ListNode(vec[0]);
    ListNode* mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* temp = new ListNode(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    cout<<(isPalindrome(head) ? "It is a palindrome" : "It is not a palindrome");
}