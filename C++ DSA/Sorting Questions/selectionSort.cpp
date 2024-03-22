//Sorts the leftmost element first

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSortI(vector<int>& arr){
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

void selectionSortII(vector<int>& arr){
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
    vector<int> inp = {5,9,2,7,6,3};
    selectionSortI(inp);
    for(auto i:inp){
        cout<<i<<" ";
    }
}

//Time complexity is: O(n^2)