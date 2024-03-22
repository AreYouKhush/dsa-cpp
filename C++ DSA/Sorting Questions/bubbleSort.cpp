//Sorts the rightmost element first

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    int flag = true;
    for(int i = 0; i < arr.size() && flag; i++){
        flag = false;
        for(int j = 1; j < arr.size() - i; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
                flag = true;
            }
        }
    } 
}

int main(){
    // vector<int> inp = {9,8,7,6,5,4,3,2,1,0};
    vector<int> inp = {0,1,2,3,4,5,6,7,8,9};
    bubbleSort(inp);
    for(auto i:inp){
        cout<<i<<" ";
    }
}

// Best Time Complexity : O(n)
// Time complexity is: O(n^2)