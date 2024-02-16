#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swapAlternate(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    while(i < n-1){
        swap(nums[i], nums[i+1]);
        i += 2;
    }
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    swapAlternate(vec);
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}