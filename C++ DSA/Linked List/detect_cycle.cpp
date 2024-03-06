#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool detectCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

ListNode* detectCycleII(ListNode* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }  
    return nullptr;
}

int lengthOfCycle(ListNode* head){
    int length = 0;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            slow = slow->next;
            while(slow != fast){
                slow = slow->next;
                length++;
            }
            return length;
        }
    }  
    return length;
}

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    ListNode* head = new ListNode(vec[0]);
    ListNode* mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* temp = new ListNode(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    int pos = 3;
    ListNode* cyclePosition = head;
    for(int i = 0; i < pos; i++){
        cyclePosition = cyclePosition->next;
    }
    mover->next = cyclePosition;

    cout<<"Is there a cycle: "<<(detectCycle(head) ? "Yes" : "No")<<endl;

    ListNode* cycleNodePosition = detectCycleII(head);
    cout<<"Value at Starting Cycle Node: "<<cycleNodePosition->val<<endl;

    cout<<"Length of Loop: "<<lengthOfCycle(head);
}