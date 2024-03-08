#include<bits/stdc++.h>
using namespace std;

/*
    Arr -> n-length
    k painters
    1 unit board = 1 unit time
    painter -> contiguous section
*/

bool isPossible(vector<int>& arr, int boards, int painters, int mid){
    int paintCount = 1;
    int pageSum = 0;
    for(int i = 0; i < boards; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            paintCount++;
            if(paintCount > painters){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int paint(vector<int>& arr, int boards, int painters){
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(start < boards){
        int mid = start + (end - start)/2;
        if(isPossible(arr, boards, painters, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {5,5,5,5};
    int painters = 5;
    cout<<paint(vec, vec.size(), painters);
}