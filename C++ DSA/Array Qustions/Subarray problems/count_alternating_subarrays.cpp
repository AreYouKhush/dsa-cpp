#include<bits/stdc++.h>
using namespace std;

long long countAlternatingSubarrays(vector<int>& nums) {
    if(nums.size() == 1) return 1;
    int totalSubarrays = 0;
    int i = 0, j = 1;
    while(j <= nums.size()){
        int count = 1;
        while(j < nums.size() && nums[j - 1] != nums[j]){
            count++;
            j++;
        }
        totalSubarrays += (count * (count + 1))/2;
        i = j;
        j = j + 1;
    }
    return totalSubarrays;
}

int main(){
    vector<int> nums = {0,1,1,0,0,1};
    cout<<countAlternatingSubarrays(nums);
}