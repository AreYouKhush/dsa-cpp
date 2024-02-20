#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp = "nRonnyn";
    char character = 'n';
    string op = "";
    for(int i = 0; i < inp.size();i++){
        if(inp[i] != character){
            op += inp[i];
        }
    }
    cout<<op;
}