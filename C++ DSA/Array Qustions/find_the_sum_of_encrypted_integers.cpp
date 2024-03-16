#include<bits/stdc++.h>
using namespace std;

int sumOfEncryptedInt(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        int maxNum = 0;
        int size = 0;
        while(nums[i] > 0){
            int temp = nums[i] % 10;
            maxNum = max(maxNum, temp);
            nums[i] /= 10;
            size++;
        }
        int temp = 0;
        while(size > 0){
            temp = (temp*10) + maxNum;
            size--;
        }
        sum += temp;
    }
    return sum;
}

int main(){
    vector<int> inp = {11,22,33};
    cout<<sumOfEncryptedInt(inp);
}