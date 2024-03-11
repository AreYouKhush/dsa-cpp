/*

    Heap is a complete binary tree that comes with a heap order property.

    A CBT is a tree where:
        1. Every level is completely filled except possibly the last level
        2. Nodes are filled from the left.

    Types of Heaps:- 
        1. Max-heap
        2. Min-heap

    Heap tree properties:-
        1. Structural Integrity 
        2. Order

    Heap Tree Construction:-
        1. Insert key one by one in the given order O(nlogn)
        2. Heapify method O(n)

    Heap Tree Using one key insertion at a time Algorithm:-
        1. Insert key one by one to insert a key into empty tree takes O(1) time.
        2. To insert a key into already constructed heap in worst case is O(log(n)) comparison and O(log(n)) for swapping.
        3. Total n elements so O(nlogn) time.

    Heapify algorithm:
        1. 
        2.
        3.
        4.
        5.

    Heap representation in array form:-
        1. If node is at ith position, then
        (FOR 1 indexed array)
        2. left child -> 2*i index
        3. right child -> 2*i+1 index
        4. parent = floor(i/2)

    Operations on Heaps

    1. Heapify → Process to rearrange the heap in order to maintain heap-property.
    2. Find-max (or Find-min) → find a maximum item of a max-heap, or a minimum item of a min-heap, respectively.
    3. Insertion → Add a new item in the heap.
    4. Deletion → Delete an item from the heap.
    5. Extract Min-Max → Returning and deleting the maximum or minimum element in max-heap and min-heap respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
        vector<int> heap;
        bool maxHeap;

    public:
    Heap(vector<int>& arr, bool maxHeap){
        this->heap = arr;
        this->maxHeap = maxHeap;
    }

    // To heapify a subtree rooted with node i which is
    // an index vector<int>& arr. N is size of heap
    void max_heapify(vector<int>& arr, int N, int i){
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < N && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            max_heapify(arr, N, largest);
        }
    }
        
    void min_heapify(vector<int>& arr, int size, int i){
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l < size && arr[l] < arr[smallest]){
            smallest = l;
        }

        if(r < size && arr[r] < arr[smallest]){
            smallest = r;
        }

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            min_heapify(arr, size, smallest);
        }
    }

    void insert(int k){
        this->heap.emplace_back(k);
        int index = this->heap.size() - 1;
        if(this->heap.size() == 0){
            this->heap.emplace_back(k);
            return;
        }
        while(index > 0){
            int parent = (index/2) - 1 > 0 ? (index/2) - 1 : 0;
            cout<<parent<<endl;
            if(this->heap[parent] < this->heap[index]){
                swap(this->heap[parent], this->heap[index]);
                index = parent;
            }else{
                break;
            }
        }
    }

    void deleteRoot(){
        /*
            1. Put last node in the root position
            2. Remove last node
            3. Propagate root node to its correct position
        */
       vector<int>& arr = this->heap;
       if(arr.size() == 0)return;
       if(arr.size() == 1){
            arr.clear();
            return;
       }
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        int index = 0;
        while(index < arr.size()){
            int l = (index * 2) + 1;
            int r = (index * 2) + 2;
            cout<<l<<" "<<r<<" "<<index<<endl;
            if(l < arr.size() && arr[l] > arr[index] && r < arr.size() && arr[l] >= arr[r]){
                swap(arr[index], arr[l]);
                index = l;
            }else if(r < arr.size() && arr[r] > arr[index] && arr[l] <= arr[r]){
                swap(arr[index], arr[r]);
                index = r;
            }else if(l < arr.size() && arr[l] > arr[index]){
                swap(arr[index], arr[l]);
                index = l;
            }else{
                break;
            }
        }
    }

    // Function to build a Max-Heap from the given array
    void buildHeap(){
        // Index of last non-leaf node
        int startIdx = (this->heap.size() / 2) - 1;

        // Perform reverse level order traversal
        // from last non-leaf node and heapify
        // each node
        for (int i = startIdx; i >= 0; i--) {
            if(this->maxHeap){
                max_heapify(this->heap, this->heap.size(), i);
            }else{
                min_heapify(this->heap, this->heap.size(), i);
            }
        }
    }

    // A utility function to print the array
    // representation of Heap
    void printHeap(){
        cout << "Array representation of Heap is:\n";

        for (int i = 0; i < this->heap.size(); ++i)
            cout << this->heap[i] << " ";
        cout << "\n";
    }
};

int main(){
    vector<int> arr = {3,7,2,1,7,4,8,3,11,23};
    //True for max_heap, false for min_heap
    Heap max_heap(arr, true);
	int N = arr.size();

	max_heap.buildHeap();
	// max_heap.printHeap();

    int choice = 0;
    while(choice < 4){
        cout<<"Choose an operation: "<<endl;
        cout<<"1. Insert\n2. Delete\n3. Print\nAny to Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int num;
            cout<<"Enter a number: ";
            cin>>num;
            max_heap.insert(num);
        
        case 2:
            max_heap.deleteRoot();

        case 3:
            max_heap.printHeap();

        case 4:
            break;

        default:
            break;
        }
    }
	return 0;
}
