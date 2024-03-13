#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> arr){
    if(arr.size() == 0){
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next =  temp;
        mover = mover->next;
    }
    return head;
}

void printList(vector<ListNode*> lists){
    for(auto it: lists){
        while(it){
            cout<<it->val<<" ";
            it = it->next;
        }
    }
}

int countTotalNodes(vector<ListNode*> lists){
    int count = 0;
    for(auto it: lists){
        while(it){
            count++;
            it = it->next;
        }
    }
    return count;
}

ListNode* mergeKListsI(vector<ListNode*>& lists) {
    ListNode* head = new ListNode();
    ListNode* mover;
    int smallest = INT_MAX;
    int indexHolder = 0;
    int totalNodes = countTotalNodes(lists);
    int count = 0;
    while(count < totalNodes){
        int i = 0;
        while(i < lists.size()){
            if(lists[i]){
                if(lists[i]->val <= smallest){
                    smallest = lists[i]->val;
                    indexHolder = i;
                }
            }
            i++;
        }
        if(count == 0){
            head->val = smallest;
            mover = head;
        }else{
            ListNode* temp = new ListNode(smallest);
            mover->next = temp;
            mover = mover->next;
        }
        smallest = INT_MAX;
        lists[indexHolder] = lists[indexHolder]->next;
        count++;
    }
    return head;
}

//Better approach
ListNode* mergeKListsII(vector<ListNode*> lists){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it: lists){
        while(it){
            pq.push(it->val);
            it = it->next;
        }
    }
    if(pq.empty()){
        return NULL;
    }
    ListNode* head = new ListNode(pq.top());
    ListNode* mover = head;
    pq.pop();
    while(!pq.empty()){
        ListNode* temp = new ListNode(pq.top());
        pq.pop();
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int main(){
    vector<vector<int>> vec = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> lists;
    for(auto it: vec){
        ListNode* temp = createLinkedList(it);
        lists.push_back(temp);
    }
    ListNode* head = mergeKListsII(lists);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    // printList(lists);
}