#include<bits/stdc++.h>
using namespace std;

class minStack
{
	vector<int> st;
	vector<int> minSt;
	
	public:	
	// Constructor
    minStack() { 
        // Write your code here.
    }
    
    // Function to add another element equal to num at the top of stack.
    void push(int num){
        // Write your code here.
        st.push_back(num);
        int count = 0;
        if(minSt.size() == 0){
            minSt.push_back(num);
        }else{
            while(minSt.size() != 0 && num > minSt[minSt.size() - 1]){
                st.push_back(minSt[minSt.size() - 1]);
                minSt.pop_back();
                count++;
            }
            int temp = count;
            while(count >= 0){
                if(count == temp){
                    minSt.push_back(num);
                    count--;
                }else{
                    minSt.push_back(st[st.size() - 1]);
                    st.pop_back();
                    count--;
                }
            }
        }
    }
    
    // Function to remove the top element of the stack.
    int pop(){
        // Write your code here.
        if(st.size() == 0){
            return -1;
        }else{
            int ans = st[st.size() - 1]; 
            int count = 0;
            while(minSt[minSt.size()-1] != ans){
                st.push_back(minSt[minSt.size()-1]);
                minSt.pop_back();
                count++;
            }
            if(minSt[minSt.size()-1] == ans){
                minSt.pop_back();
            }
            while(count > 0){
                minSt.push_back(st[st.size() - 1]);
                st.pop_back();
                count--;
            }
            st.pop_back();
            return ans;
        }
    }
    
    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top(){
        // Write your code here.
        if(st.size() == 0){
            return -1;
        }else{
            return st[st.size() - 1];
        }
    }
    
    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin(){
        // Write your code here.
        if(minSt.size() == 0){
            return -1;
        }else{
            return minSt[minSt.size() - 1];
        }
    }

    void display(){
        cout<<endl<<"STACK: "<<endl;
        for(auto it: st){
            cout<<it<<" ";
        }
        cout<<endl<<"MINSTACK: "<<endl;
        for(auto it: minSt){
            cout<<it<<" ";
        }
    }
};

int main(){
    minStack ms;
    ms.push(7);
    ms.push(5);
    ms.push(9);
    ms.push(2);
    ms.push(6);
    for(int i = 0; i < 6; i++){
        cout<<ms.pop()<<" ";
        cout<<ms.getMin()<<endl;
    }
}