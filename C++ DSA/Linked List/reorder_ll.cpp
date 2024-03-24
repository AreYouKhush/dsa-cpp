#include<bits/stdc++.h>
using namespace std;

class List{
    public:
    int data;
    List* next;
    List(){
        data = 0;
        next = nullptr;
    }
    List(int x){
        data = x;
        next = nullptr;
    }
    List(int x, List* p){
        data = x;
        next = p;
    }
};

void reorderListI(List* head) {
    stack<List*> s;
    List* curr = head;
    while(curr){
        s.push(curr);
        curr = curr->next;
    }
    curr = head;
    unordered_map<List*, bool> vis;
    while(true){
        List* last = s.top();
        s.pop();
        List* next = curr->next;
        vis[curr] = true;
        if(vis[last]){ 
            curr->next = NULL; 
            break; 
        } 
        curr->next = last; 
        vis[last] = true;
        curr = curr->next; 
        if(vis[next]){
            curr->next = NULL;
            break;
        }
        curr->next = next;
        curr = curr->next;
    }
}

void reorderListII(List* head){
    List* slow = head;
    List* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    List* second = slow->next;
    List* prev = nullptr;
    slow->next = nullptr;

    while(second){
        List* temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    List* first = head;
    second = prev;

    while(second){
        List* temp1 = first->next;
        List* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

int main(){
    vector<int> inp = {1,2,3,4,5,6};
    List* head = new List(inp[0]);
    List* mover = head;
    for(int i = 1; i < inp.size(); i++){
        List* temp = new List(inp[i]);
        mover->next = temp;
        mover = temp;
    }
    reorderListII(head);
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}