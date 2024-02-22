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
        while(num > minSt[minSt.size() - 1]){
            st.push_back(minSt[minSt.size() - 1]);
            minSt.pop_back();
            count++;
        }
    }
    
    // Function to remove the top element of the stack.
    int pop(){
        // Write your code here.
        if(st.size() == 0){
            return -1;
        }else{
            int ans = st[st.size() - 1];
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
};

int main(){
    minStack ms;
    ms.push(7);
    ms.push(5);
    ms.push(9);
    ms.push(2);
    cout<<ms.top();
    cout<<ms.getMin();
}