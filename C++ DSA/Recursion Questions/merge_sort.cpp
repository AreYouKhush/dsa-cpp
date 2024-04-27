#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void partition(vector<int>& nums, int i, int j) {
    if(i >= j) return;
    int mid = i + (j - i)/2;
    partition(nums, i, mid);
    partition(nums, mid+1, j);
    merge(nums, i, mid, j);
}

void mergeSort(vector<int>& nums) {
    partition(nums, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {5,2,6,8,2,8,1};
    mergeSort(nums);
    for(auto it: nums){
        cout<<it<<" ";
    }
}