#include<bits/stdc++.h>
using namespace std;

long long countSubarraysI(vector<int>& nums, int k) {
    int count = 0;
    int maxVal = 0;
    unordered_map<int, int> mpp;

    for(auto it: nums){
        mpp[it]++;
        maxVal = max(it, maxVal);
    }

    int extraSubarrayElements = 0;
    int end_idx = nums.size() - 1;

    if(mpp[maxVal] < k){
        return 0;
    }

    while(mpp[maxVal] > k){
        if(nums[end_idx] == maxVal){
            mpp[maxVal]--;
        }
        extraSubarrayElements++;
        end_idx--;
    }

    int front = 0;

    while(mpp[maxVal] >= k){
        
        while(nums[front] != maxVal && mpp[maxVal] == k){
            front++;
            count += 1 + extraSubarrayElements;
        }

        if(end_idx < nums.size() && nums[front] == maxVal){
            front++;
            mpp[maxVal]--;
            count += 1 + extraSubarrayElements;
            end_idx++;
        }

        while(end_idx < nums.size() && mpp[maxVal] != k ){
            if(nums[end_idx] == maxVal){
                mpp[maxVal]++;
            }else{
                end_idx++;
            }
            extraSubarrayElements--;
        }
        cout<<front<<" "<<end_idx<<endl;
    }   
    // cout<<end_idx<<" "<<extraSubarrayElements<<endl;
    return count;
}

long long countSubarraysII(vector<int>& nums, int k) {
    long long max_num = *max_element(nums.begin(), nums.end());
    long long count = 0;
    long long left = 0, right = 0, ans = 0;

    while(right<nums.size()){
        if(nums[right] == max_num)count++;
        
        while(count>=k){
            if(nums[left] == max_num){
                count--;   
            }
            left++;
            ans += nums.size() - right;
        }    
        right++;
    }
    return ans;    
}

int main() {
    vector<int> inp = {1,2,3,2,5,3,4,5,5,4,5,2};

    //TODO: Error for below text case in CountSubarratsI():
    // vector<int> inp = {37,20,38,66,34,38,9,41,1,14,25,63,8,12,66,66,60,12,35,27,16,38,12,66,38,36,59,54,66,54,66,48,59,66,34,11,50,66,42,51,53,66,31,24,66,44,66,1,66,66,29,54};
    cout<<countSubarraysII(inp, 2);
}