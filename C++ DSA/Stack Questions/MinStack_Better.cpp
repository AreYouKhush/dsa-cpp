#include<bits/stdc++.h>
using namespace std;

// Implement class for minStack.
class minStack
{
	// Write your code here.
    vector<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(st.size() == 0){
                st.push_back(make_pair(num, num));
            }else{
                st.push_back(make_pair(num, min(num, st.back().second)));
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(st.size() == 0){
                return -1;
            }else{
                int ans = st.back().first;
                st.pop_back();
                return ans;
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(st.size() == 0){
                return -1;
            }else{
                int ans = st.back().first;
                return ans;
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(st.size() == 0){
                return -1;
            }else{
                int ans = st.back().second;
                return ans;
            }
		}

        void display(){
            for(auto it : st){
                cout<<it.first<<" "<<it.second<<endl;
            }
            cout<<endl;
        }
};

int main(){
    minStack ms;
    ms.push(7);
    ms.push(1);
    ms.push(5);
    ms.push(9);
    ms.push(6);
    ms.display();
    for(int i = 0; i < 6; i++){
        cout<<ms.pop()<<" ";
        cout<<ms.getMin()<<endl;
    }
}