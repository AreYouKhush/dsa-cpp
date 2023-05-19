#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;
void sort012(vector<int> arr, int n) {
    
    for(int i=0, j=1, k=n-1; i<=k;) {
        if (arr[i]==0) {
            i++;
            j++;
        }
        
        if (arr[i]==2) {
            swap(arr[i], arr[k]);
        }
    }

    for (int i=0; i<n; i++) {
        cout<<arr[i];
    }
}

int main() {

    vector<int> arr{2,1,1,0,0};
    return 0;
}