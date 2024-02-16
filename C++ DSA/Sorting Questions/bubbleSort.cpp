//Sorts the rightmost element first

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    int end = arr.size() - 1;
    for(int i = 0; i <= end; i++){
        int next = 0;
        int swaps = 0;

        for(int j = 1; j <= end - i; j++, next++){
            if(arr[next] > arr[j]){
                swap(arr[next], arr[j]);
                swaps++;
            }
        }
        //If array has already been sorted exit
        if(swaps == 0){
            break;
        }
        cout<<"Step "<<i+1<<": ";
        for(auto i:arr){
            cout<<i<<" ";
        }cout<<endl;
    }
}

int main(){
    vector<int> inp = {9,8,7,6,5,4,3,2,1,0};
    selectionSort(inp);
    for(auto i:inp){
        cout<<i<<" ";
    }
}

// Best Time Complexity : O(n)
// Time complexity is: O(n^2)