#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size()-1;
    int tempSum = 0;
    while(i < j){
        tempSum = numbers[i] + numbers[j];
        if(tempSum == target){
            return {i, j};
        }else if(tempSum > target){
            j--;
        }else if(tempSum < target){
            i++;
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    vector<int> ans = twoSum(vec, 16);
    for(auto it: ans){
        cout<<it<<" ";
    }
}