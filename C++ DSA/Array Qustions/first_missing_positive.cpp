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

int firstMissingPositiveII(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = 1;
    int prev = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0 && nums[i] != n && nums[i] != prev){
            return n;
        }
        if(nums[i] > 0 && nums[i] != prev){
            n++;
        }
        prev = nums[i];
    }
    return n;
}

// Using input array as memory/ hash set
int firstMissingPositiveIII(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0){
            nums[i] = 0;
        }
    }

    for(int i = 0; i < nums.size(); i++){
        int temp = abs(nums[i]);
        if(temp >= 1 && temp <= nums.size()){
            if(nums[temp - 1] > 0){
                nums[temp - 1] *= -1;
            }else if(nums[temp - 1] == 0){
                nums[temp - 1] = -1 * (nums.size() + 1);
            }
        }
    }

    for(int i = 1; i <= nums.size() + 1; i++){
        if(nums[i - 1] >= 0){
            return i;
        }
    }

    return 1;
}

int main(){
    vector<int> inp = {-1,-4};
    cout<<firstMissingPositiveIII(inp);
}