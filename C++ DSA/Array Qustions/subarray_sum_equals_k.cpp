#include<bits/stdc++.h>
using namespace std;

//Two Pointers will not work here because it has both negative ans positive numbers!!!!!!!!!!!
//This only works for Positive numbers in an array!!
int subarraySumOnlyPositive(vector<int>& nums, int k) {
    int i = 0, j = 0;
    int sum = 0;
    int count = 0;
    while(j < nums.size()){
        sum += nums[j];
        if(sum == k && i <= j){
            count++;
            sum -= nums[i];
            i++;
        }else if(sum > k){
            while(sum > k && i < j){
                sum -= nums[i];
                i++;
            }
            if(sum == k){
                count++;
            }
        }
        j++;
    }
    return count;
}

int subarraySum(vector<int>& nums, int k){
    unordered_map<int, int> mpp;
    int preSum = 0;
    int count = 0;
    mpp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        preSum += nums[i];
        int remaining = preSum - k;
        count += mpp[remaining];
        mpp[preSum]++;
    }
    return count;
}

int main(){
    vector<int> inp = {1,2,3};
    cout<<subarraySum(inp, 3);
}