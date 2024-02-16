#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int count = 0;
    if(n <= 2){
        return false;
    }
	for(int i = 1; i < sqrt(n); i++){
		count = count + (n % i == 0);
	}
    return count <= 1;
}

int main(){
    int n = 500;
    cout<<isPrime(n);
}