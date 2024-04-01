#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0) return 0;
    int res = 0;
    int i = 0, j = 0;
    int prod = 1;
    while(j < nums.size()){
        prod *= nums[j];
        j++;
        while(i < j && prod >= k){
            prod /= nums[i];
            i++;
        }
        res += (j - i);
    }    
    
    return res;
}

int main(){
    vector<int> inp = {10,5,2,6};
    cout<<numSubarrayProductLessThanK(inp, 100);
}