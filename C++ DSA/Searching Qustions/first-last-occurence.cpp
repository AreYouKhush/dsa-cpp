#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int leftOccurence(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(nums[mid] == target){
            ans = mid;
            end = mid - 1;
        }else if(nums[mid] < target){
            start = mid + 1;
        }else if(nums[mid] > target){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

// int rightOccurence(vector<int>& nums, int target){
//     int start = 0;
//     int end = nums.size() - 1;
//     int ans = -1;
//     int mid = start + (end - start)/2;
//     while(start <= end){
//         if(nums[mid] == target){
//             ans = mid;
//             start = mid + 1;
//         }else if(nums[mid] < target){
//             start = mid + 1;
//         }else if(nums[mid] > target){
//             end = mid - 1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return ans;
// }

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range;
    range.push_back(leftOccurence(nums, target));
    // range.push_back(rightOccurence(nums, target));
    return range;
}

int main(){
    vector<int> inp = {1,2,2,2,2,3,3,3,5,5,5};
    int n = inp.size();
    int target = 2;
    vector<int> ans = searchRange(inp, target);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}