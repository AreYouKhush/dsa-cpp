#include <bits/stdc++.h>
using namespace std;

/*
    Approach :- The main idea is to remove the element at the peak. As its empty we replace it by the element at the end of the heap(bottommost element). Now to maintain the heap property that the element is larger that both its children, we continuously move the element replacing it with the greater child.

    Algorithm:
    1. Save the element in the peak of heap
    2. remove the last element and place it at the peak
    3. assign the position of this element to a variable say ‘pos’ which is 0
    4. run a loop indefinitely
    5. if element  at ‘pos’ is larger than both its children
    6. break the loop
    7. else replace it with the larger child and assign ‘pos’ with the position it replaced to.
    
    Time Complexity :- O(log(n)) where ‘n’ is the size of the heap
    We traverse the heap level wise and as there are log(n) levels in a binary heap the Time Complexity is O(log(n)).

    Space Complexity :- O(1) We are not using any extra space in any operation.
*/

int pop(vector<int> &heap)
{
    if (heap.size() == 0)
        return -1;
    // The top most element of heap is he largest.
    int ans = heap[0];

    // Removing the last element in heap and inserting it in top.
    heap[0] = heap.back();
    heap.pop_back();

    // Edge case.
    if (heap.size() == 0)
        return ans;
    // Shifting the current element down till its correct position.
    int pos = 0;
    while (true)
    {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int leftvalue = 0, rightvalue = 0;

        // To avoid segementation fault.
        if (left < heap.size())
            leftvalue = heap[left];
        if (right < heap.size())
            rightvalue = heap[right];

        // Swapping it by the larger value.
        if (leftvalue <= heap[pos] && rightvalue <= heap[pos])
        {
            // As it is larger than both its children it is at its correct position.
            break;
        }
        else if (leftvalue >= rightvalue)
        {
            swap(heap[pos], heap[left]);
            pos = left;
        }
        else
        {
            swap(heap[pos], heap[right]);
            pos = right;
        }
    }
    return ans;
}

// Code Snippet of the push function:
//
//     void push(vector<int> &heap, int x){
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position.
//                  break;
//              }
//          }
//      }