#include<bits/stdc++.h>
using namespace std;

//Using division operator
vector<int> productExceptSelfI(vector<int>& nums) {
    int zero = 0;
    int totalProduct = 1;
    for(auto it: nums){
        if(it == 0){
            if(zero == 0){
                zero = 1;
            }else{
                totalProduct = 0;
                break;
            }
        }else{
            totalProduct *= it;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(totalProduct == 0){
            nums[i] = 0;
        }else if(zero == 1 && nums[i] != 0){
            nums[i] = 0;
        }else if(nums[i] == 0){
            nums[i] = totalProduct;
        }else{
            nums[i] = totalProduct/nums[i];
        }
    }
    return nums;
}

//Withour using division operator
vector<int> productExceptSelfII(vector<int>& nums){
    vector<int> ans(nums.size(), 0);
    int prod = 1;
    for(int i = 0; i < ans.size(); i++){
        ans[i] = prod;
        prod *= nums[i];
    }
    prod = 1;
    for(int i = ans.size() - 1; i >= 0; i--){
        ans[i] *= prod;
        prod *= nums[i];
    }
    return ans;
}

int main(){
    vector<int> inp = {-1,1,0,-3,3};
    vector<int> ans = productExceptSelfII(inp);
    for(auto it: ans){
        cout<<it<<" ";
    }
}