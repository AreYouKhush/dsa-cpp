#include<bits/stdc++.h>
using namespace std;

bool checkIfVowel(char s){
    if(s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U'){
        return true;
    }
    return false;
}

int LCS(string &s, string &t, int sl, int tl){
    int mat[sl+1][tl+1];
    string lcsString = "";
    for(int i = 0; i < sl; i++){
        for(int j = 0; j < tl; j++){
            if(i == 0 || j == 0){
                mat[i][j] = 0;
            }else if(s[i] == t[i] && checkIfVowel(s[i])){
                mat[i][j] = mat[i-1][j-1] + 1;
                lcsString += s[i];
            }else{
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    cout<<lcsString<<endl;
    return mat[sl-1][tl-1];
}


int main(){
    string s1 = "tiger";
    string s2 = "pigeon";
    int ans = LCS(s1, s2, s1.size(), s2.size());
    cout<<ans;
}