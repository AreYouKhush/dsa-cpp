#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	int start = m;
	int end = arr.size();
    vector<int> rev;
	for(int i = end - 1; i > m; i--){
		arr.push_back(arr[i]);
	}
    arr.erase(next(arr.begin(), m+1), next(arr.begin(), end));
}

int main(){
    vector<int> inp = {1,2,3,4,5,6};
    int m = 3;
    reverseArray(inp, m);
    for(auto i : inp){
        cout<<i<<" ";
    }
}