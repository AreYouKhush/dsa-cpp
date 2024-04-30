#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* front = head;
    ListNode* last = head->next;
    while(front != nullptr) {
        int sum = 0;
        if(front->val == 0) {
            while(last != nullptr && last->val != 0) {
                sum += last->val;
                last = last->next;
                if(last->next == nullptr && last->val == 0){
                    front->val = sum;
                    front->next = nullptr;
                    return head;
                }
            }
            front->val = sum;
            front->next = last;
            front = last;
            if(last != nullptr) last = front->next;
        }else {
            front = front->next;
            if(last != nullptr) last = last->next;
        }
    }
    return head;
}

ListNode* createList(vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* mover = head;
    for(int i = 1; i < nums.size(); i++) {
        ListNode* newNode = new ListNode(nums[i]);
        mover->next = newNode;
        mover = newNode;
    }
    return head;
}

int main() {
    vector<int> nums = {0,3,1,0,4,5,2,0};
    ListNode* head = createList(nums);
    head = mergeNodes(head);
    while(head != nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
}