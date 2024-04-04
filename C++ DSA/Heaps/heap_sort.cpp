// O(nlogn)
#include<bits/stdc++.h>
using namespace std;

/*
    Algorithm:-
        1. Swap a[0] with a[last]
        2. Now the largest element is in its correct postition
        3. Now, use heapify to put the maximum element as root.
        4. Repeat steps 1 to 3 until all are sorted
*/

void heapify(vector<int>& heap, int size, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if(l < size && heap[l] > heap[largest]){
        largest = l;
    }

    if(r < size && heap[r] > heap[largest]){
        largest = r;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, size, largest);
    }
}

void buildHeap(vector<int>& heap){
    int startIndex = (heap.size()/2) -1;

    for(int i = startIndex; i >= 0; i--){
        heapify(heap, heap.size(), i);
    }
}

void heapSort(vector<int>& heap){
    for (int i = heap.size() - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main(){
    vector<int> vec{5,9,5,6,3,8,4,8,9,5,6,2,1,0,1,8,5,6};
    buildHeap(vec);
    for(auto it: vec){
        cout<<it<<" ";
    }
    cout<<endl;
    heapSort(vec);
    for(auto it: vec){
        cout<<it<<" ";
    }
}