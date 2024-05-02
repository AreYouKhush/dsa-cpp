#include<bits/stdc++.h>
using namespace std;

int minNumberOperations(vector<int>& target) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    stack<int> st;
    int minN = INT_MAX;
    int res = 0;
    int curr = 0;
    for(int i = 0; i < target.size(); i++) {
        int t = target[i];
        if(!st.empty()){
            curr = st.top();
        }
        if(minN != INT_MAX) {
            t -= minN;
        }
        if(!st.empty() && curr > t) {
            res += curr;
            while(!st.empty()) st.pop();
            while(i < target.size() - 2 && target[i] >= target[i+1]){
                minN = target[i + 1];
                i++;
            }
            minN = target[i];
        }else{
            if(minN != INT_MAX){
                if(target[i] - minN > 0) 
                    st.push(target[i] - minN);
            }
            else {
                st.push(target[i]);
            }
        }
    }
    if(!st.empty()){
        res += st.top();
    } 
    return res;
}

int main() {
    vector<int> nums = {4,6,7,3,5,6,4,5,4,3,2,6,4,7};
    cout<<minNumberOperations(nums);
}