//Take an element and put it in it's correct position.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int size = arr.size();
    for(int i = 1; i <= size; i++){
        int j = i;
        while( j > 0 && arr[j] < arr[j - 1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
        cout<<"Step "<<i<<": ";
        for(auto it:arr){
            cout<<it<<" ";
        }cout<<endl;
    }
}

int main(){
    vector<int> inp = {1,2,3,4,5,6,7,8,9};
    insertionSort(inp);
    for(auto i:inp){
        cout<<i<<" ";
    }
}

// Worst and Average Case: O(n^2)
// Best Case: O(n)