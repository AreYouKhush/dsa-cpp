#include<iostream>
#include<math.h>
using namespace std;

void negBin(int x){
    cout<<x;
    x = x & 1;
}

int main(){
    int x = -4;
    if (x<0){
        x *= -1;
        negBin(x);
    }
    return 0;
}

