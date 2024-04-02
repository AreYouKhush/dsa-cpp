#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> inp = {{3,5,2,5,3,6}, {3,6,3,2,3}, {8,5,7,9,2}};
    int sum = 0;
    for(int i = 0; i < inp.size(); i++){
        for(int j = 0; j < inp[i].size(); j++){
            sum += inp[i][j];
        }
    }
    cout<<sum;
}