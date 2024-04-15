#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ones = {1,1,0,1,1,1};
    int maxSize = 0;
    int size = 0;

    for(auto it: ones){
        if(it == 1){
            size++;
            maxSize = max(maxSize, size);
        }else{
            size = 0;
        }
    }
    cout<<maxSize;
}