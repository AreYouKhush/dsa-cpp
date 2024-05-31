#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // CONCEPT OF BUCKETS
    vector<int> singleNumber(vector<int>& nums) {
        long long tot_xor = 0;
        for(int i = 0; i < nums.size(); i++) {
            tot_xor ^= nums[i];
        }
        int b1 = 0;
        int b2 = 0;
        int rightmost = (tot_xor & tot_xor-1) ^ tot_xor;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & rightmost) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }
        return {b1, b2};
    }
};

int main() {
    return 0;
}