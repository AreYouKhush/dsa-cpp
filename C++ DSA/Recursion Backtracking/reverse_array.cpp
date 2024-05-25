#include<bits/stdc++.h>
using namespace std;

//Using two pointers
void reverseArray(vector<int>& nums, int i, int j) {
    if(i >= j) return;
    swap(nums[i], nums[j]);
    reverseArray(nums, i+1, j-1);
}

//Using one pointer
void reverseArray2(vector<int>& nums, int i) {
    if(i >= nums.size()/2) return;
    swap(nums[i], nums[nums.size() - i - 1]);
    reverseArray2(nums, i+1);
}

int main() {
    vector<int> nums = {2,5,3,6,1,7};
    cout<<"Before: \n";
    for(auto it: nums) {
        cout<<it<<" ";
    }
    cout<<"\nAfter: \n";
    reverseArray(nums, 0, nums.size() - 1);
    for(auto it: nums) {
        cout<<it<<" ";
    }
    cout<<"\nSwap 2: \n";
    reverseArray2(nums, 0);
    for(auto it: nums) {
        cout<<it<<" ";
    }
}