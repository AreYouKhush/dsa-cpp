#include<bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k){
    int mask = 1 << k-1;
    if((n&mask) == 0){
        return false;
    }
    return true;
}

int main(){
    int n = 65;
    int k = 4;
    cout<<isKthBitSet(n, k);
}