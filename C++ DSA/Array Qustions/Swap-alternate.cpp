#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size() - i; j++){
            if(nums[i] < nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}

vector<int> swapAlternate(vector<int> &nums){
    vector<int> ans(nums.size(), 0);
    // sort(nums.begin(), nums.end());
    bubbleSort(nums);
    int even, odd;
    if(nums[0] % 2 == 0){
        even = 0;
        odd = 1;
    }else{
        even = 1;
        odd = 0;
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            ans[even] = nums[i];
            even += 2;
        }else{
            ans[odd] = nums[i];
            odd += 2;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {9,8,13,2,19,14};
    vector<int> ans = swapAlternate(vec);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}