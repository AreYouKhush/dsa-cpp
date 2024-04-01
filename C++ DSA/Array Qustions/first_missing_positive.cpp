#include<bits/stdc++.h>
using namespace std;

int firstMissingPositiveI(vector<int>& nums) {
    unordered_map<int, int> mpp;
    for(auto it: nums){
        mpp[it]++;
    }
    for(int i = 1; i <= nums.size() + 1; i++){
        if(mpp.count(i) == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    vector<int> inp = {2,3,1,5,34,6,2};
    cout<<firstMissingPositiveI(inp);
}