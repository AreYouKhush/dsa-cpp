#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int first = 0, last = nums.size(), mid = 0;
    while(first <= last){
        mid = (last - first)/2 + first;
        if(target > nums[mid]){
            first = mid + 1;
        }else if(target < nums[mid]){
            last = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> i{1,2,3,4,5,6,7,8};
    cout<<searchInsert(i, 1);
    cout<<searchInsert(i, 2);
    cout<<searchInsert(i, 3);
    cout<<searchInsert(i, 4);
    cout<<searchInsert(i, 5);
    cout<<searchInsert(i, 6);
    cout<<searchInsert(i, 7);
    cout<<searchInsert(i, 8);
    cout<<searchInsert(i, 9);
}