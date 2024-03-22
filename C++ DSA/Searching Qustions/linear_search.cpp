#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> inp = {5,9,6,3,5,8,6};
    int key = 8;
    for(auto it: inp){
        if(it == key){
            cout<<"Found";
        }
    }
}