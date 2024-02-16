#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countDigits(int n)
{
    // Initializing 'cur' and 'ans'.
    int cur = n, ans = 0;

    // Iterating while 'cur' > 0.
    while (cur > 0)
    {
        // 'd_0' gives us the digit at 'ones' place decimal notation of 'cur'.
        int d_0 = cur % 10;
        if (d_0 != 0)
        {
            // Incrementing 'ans' by 1 if current digit divides 'n' evenly.
            ans += (n % d_0) == 0;
        }
        cur /= 10;
    }
    return ans;
} 

int main(){
    int n = 103;

    // int a = log10(n) + 1;
    // cout<<a<<endl;
    // int count = 0;
    // int cur = n;
    // while(cur != 0){
    //     int i = cur % 10;
    //     while (i == 0){
    //         cur /= 10;
	// 	    i = cur % 10;
	// 	}
    //     if( n % i == 0){
    //         count++;
    //     }
    //     cur /= 10;
    // }
    // cout<<count;

    cout<<countDigits(n);

    return 0;
}