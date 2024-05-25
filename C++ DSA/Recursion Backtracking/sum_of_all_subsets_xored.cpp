#include<bits/stdc++.h>
using namespace std;

int subset(vector<int>& arr,int i,int x){
    if(i >= arr.size()){
        return x;
    }
    int a = subset(arr,i+1,x);
    int b = subset(arr,i+1,x^arr[i]);
    return a + b;
}

int subsetXORSum(vector<int>& nums) {
    return subset(nums,0,0);
    
}

int main() {
    vector<int> nums = {3,2,5,6,1,7};
    cout<<subsetXORSum(nums)<<endl;
    return 0;
}