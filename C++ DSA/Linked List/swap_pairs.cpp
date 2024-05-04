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

// Swapping values
ListNode* swapPairsI(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    // ListNode* newHead = head->next;
    ListNode* front = head;
    ListNode* nextNode = head->next;

    while(front != nullptr && nextNode != nullptr) {
        swap(front->val, nextNode->val);
        // front->next = nextNode->next;
        // nextNode->next = front;
        // front = front->next;
        // if(front != nullptr) nextNode = front->next;
        front = nextNode->next;
        if(front != nullptr) nextNode = front->next;
    }

    return head;
}

//Swapping Nodes
ListNode* swapPairsII(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = head->next;
    ListNode* front = head;
    ListNode* nextNode = head->next;
    while(front != nullptr && nextNode != nullptr) {
        ListNode* prevFront = front;
        ListNode* temp = nextNode->next;
        nextNode->next = front;
        front = temp;
        if(temp != nullptr){
            prevFront->next = temp->next;
            nextNode = temp->next;
        }
        if(temp == nullptr || temp->next == nullptr){
            prevFront->next = temp;
        }
    }
    return newHead;
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
    // vector<int> nums = {5,4,2,3};
    vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {0,3,1,0,4,5,2,0};
    ListNode* head = createList(nums);
    head = swapPairsII(head);
    while(head != nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
}