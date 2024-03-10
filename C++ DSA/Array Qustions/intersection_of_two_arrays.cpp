#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    int i = 0;
    int j = 0;
    int temp = -1; 
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            temp = nums1[i];
            i++;
            j++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else{
            i++;
        }
        while(nums1[i] == temp && i < nums1.size()){
            i++;
        }
        while(nums2[j] == temp && j < nums2.size()){
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ans = intersection(nums1, nums2);
    for(auto it: ans){
        cout<<it<<" ";
    }
}