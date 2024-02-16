#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int euclideanAlgo(int n, int m){
    if (m == 0) {
        return n;
    }
    euclideanAlgo(m, n % m);
}

int main(){
    int n, m;
    cin>>n;
    cin>>m;
    cout<<"HCF: "<<euclideanAlgo(n, m);
    return 0;
}