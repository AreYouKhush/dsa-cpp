/*
    Write a function that counts the number of ways you can partition n objects using parts upto m (assuming m >= 0)
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int n, int m){
    if(n == 0){
        return 1;
    }else if(m == 0 || n < 0){
        return 0;
    }else{
        return partition(n-m, m) + partition(n, m-1);
    }   
}

int main(){
    cout<<partition(2, 2);
}