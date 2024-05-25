#include<bits/stdc++.h>
using namespace std;

int calc(int x){
    if(x <= 0){
        return 0;
    }
    return x + calc(x - 1);
}

int main(){
    int x = 1;
    cout<<calc(0);
}