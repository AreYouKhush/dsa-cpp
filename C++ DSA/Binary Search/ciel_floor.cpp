#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair<int, int> res = {INT_MIN, INT_MAX};
    for(int i = 0; i < n; i++) {
        if(arr[i] <= x && arr[i] > res.first) {
            res.first = arr[i];
        }
        if(arr[i] >= x && arr[i] < res.second) {
            res.second = arr[i];
        }
    }
    if(res.first == INT_MIN) res.first = -1;
    if(res.second == INT_MAX) res.second = -1;
    return res;
}

int main() {
    return 0;
}