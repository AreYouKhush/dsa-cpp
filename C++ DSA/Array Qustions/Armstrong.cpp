#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 54748;
    int ans = 0;
	int m = n;
	int p = ceil(log10(n));
	while(m != 0){
		int i = m % 10;
		ans += pow(i, p);
		m /= 10;
	}
	if(ans == n){
		cout<<"True";
	}else{
		cout<<"False";
	}
}