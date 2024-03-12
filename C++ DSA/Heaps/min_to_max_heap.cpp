#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int>& arr, int size, int parent){
    int largest = parent;
    int l = (largest*2) + 1;
    int r = (largest*2) + 2;
    if(l < size && arr[largest] < arr[l]){
        largest = l;
    }
    if(r < size && arr[largest] < arr[r]){
        largest = r;
    }
    if(largest != parent){
        swap(arr[largest], arr[parent]);
        max_heapify(arr, size, largest);
    }else{
        return;
    }
}

void buildHeap(vector<int>& heap){
    int startIdx = (heap.size() / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        max_heapify(heap, heap.size(), i);
    }
}

int main(){
    vector<int> minHeap{1,2,3,6,7,8};
    buildHeap(minHeap);
    for(int i = 0; i < minHeap.size(); i++){
        cout<<minHeap[i]<<" ";
    }
}