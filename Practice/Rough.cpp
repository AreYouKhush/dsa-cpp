#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    
    for(int i = 0; i < (n*2)-1; i++){
        for(int j = 0; j < (n*2)-1; j++){
            int top = i;
            int left = j;
            int right = (2*n-2) - j;
            int bottom = (2*n-2) - i;
            cout<<(n - min(min(top, left), min(bottom, right)));
        }
        cout<<endl;
    }
}