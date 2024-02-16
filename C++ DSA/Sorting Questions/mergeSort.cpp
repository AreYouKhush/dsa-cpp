//Merge sort has a time complexity: O(nlogn)
//Space Complexity is: O(n)
//Divide and merge

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void divide(vector<int>& arr, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low)/2;
    divide(arr, low, mid);
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr, int size){
    divide(arr, 0, size - 1);
}

int main(){
    vector<int> inp = {5,9,6,1,5,0, 1, 1, 1, 1};
    int n = inp.size();
    mergeSort(inp, n);
    for(auto i:inp){
        cout<<i<<" ";
    }cout<<endl;
}