#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0;
    int len = 0;
    int maxLen = 0;
    while(j < nums.size()){
        while(j < nums.size() && nums[j] == 0 && k != 0){
            k--;
            len++;
            j++;
        }
        while(j < nums.size() && nums[j] == 1){
            len++;
            j++;
        }
        maxLen = max(len, maxLen);
        while(i <= j && k == 0 && nums[j] == 0){
            if(nums[i] == 0){
                i++;
                k++;
                len--;
            }else{
                i++;
                len--;
            }
        }
    }
    return maxLen;
}

int main(){
    vector<int> inp = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<longestOnes(inp, k);
}