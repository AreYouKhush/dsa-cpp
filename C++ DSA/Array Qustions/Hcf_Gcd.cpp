#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n;
    cin>>m;

    for(int i = min(n, m); i != 0; i--){
        if(n % i == 0 && m % i == 0){
            cout<<i<<endl;
            break;
        }
    }
}