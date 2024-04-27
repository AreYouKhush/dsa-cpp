#include<bits/stdc++.h>
using namespace std;

//O(2^n) or exponential
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n = 23;
    cout<<fib(n);
}