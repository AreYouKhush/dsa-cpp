#include<bits/stdc++.h>
using namespace std;

// You can only move down or right 1 unit at a time

int paths(int n, int m){
    if(n == 1 || m == 1){
        return 1;
    }
    return paths(n, m - 1) + paths(n - 1, m);
}

int main(){
    int n = 15, m = 15;
    cout<<paths(n, m);
}