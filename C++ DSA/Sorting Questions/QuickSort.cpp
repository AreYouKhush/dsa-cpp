//Time Complexity is: O(nlogn)
//Spce Complexity is: O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int i = low;
    int j = high;
    int pivot = arr[low];
    while(i < j){
        while(arr[i] <= pivot && i <= high + 1){
            i++;
        }

        while(arr[j] > pivot && i >= low - 1){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high){ 
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main(){
    vector<int> inp = {5,9,6,1,5,0, 1, 1, 1, 1};
    int n = inp.size();
    quickSort(inp, 0, n-1);
    for(auto i:inp){
        cout<<i<<" ";
    }cout<<endl;
}