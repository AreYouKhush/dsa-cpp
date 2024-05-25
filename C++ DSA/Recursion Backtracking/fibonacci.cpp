#include<bits/stdc++.h>
using namespace std;

//O(2^n) or exponential
int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int nthfib(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    int f = 3;
    int num1 = 1;
    int num2 = 1;
    int res = 0;
    while(f <= n) {
        res = num1 + num2;
        num1 = num2;
        num2 = res;
        f++;
    }
    return res;
}

int main(){
    int n = 150;
    // cout<<fib(n);
    cout<<nthfib(n);
}