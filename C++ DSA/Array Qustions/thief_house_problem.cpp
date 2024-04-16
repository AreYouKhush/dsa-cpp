#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int prev1 = 0;
    int prev2 = 0;
    for(int num: nums){
        int temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}

int main(){
    vector<int> nums = {7,4,9,2,1,6,4,8,2};
    cout<<rob(nums);
    return 0;
}