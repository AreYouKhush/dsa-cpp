//Sorts the leftmost element first

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    int end = arr.size() - 1;
    for(int i = 0; i <= end; i++){
        for(int j = i; j <=end; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
        for(auto i:arr){
            cout<<i<<" ";
        }cout<<endl;
    }
}

int main(){
    vector<int> inp = {5,9,2,7,6,3};
    selectionSort(inp);
    for(auto i:inp){
        cout<<i<<" ";
    }
}

//Time complexity is: O(n^2)