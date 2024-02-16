#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<int> pair;
   vector<vector<int>> ans;
   for(int i = 0; i < arr.size() - 1; i++){
      for (int j = 1; j < arr.size(); j++){
         if(arr[i] + arr[j] == s){
            pair.push_back(arr[i]);
            pair.push_back(arr[j]);
            sort(pair.begin(), pair.end());
            ans.push_back(pair);
            pair.clear();
         }
      }
   }
   return ans;
}

int main(){
    vector<int> inp = {1, 2, 3, 4, 5};
    int s =  5;
    vector<vector<int>> ans = pairSum(inp, s);
    for (int i = 0; i < ans.size(); i++) {
        for ( auto it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}