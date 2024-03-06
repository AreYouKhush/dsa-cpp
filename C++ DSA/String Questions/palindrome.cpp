#include <bits/stdc++.h> 
using namespace std;

bool checkPalindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        while((tolower(s[i]) < 'a' || tolower(s[i]) > 'z') && !isdigit(s[i]) && i < j){
            i++;
        }
        while((tolower(s[j]) < 'a' || tolower(s[j]) > 'z') && !isdigit(s[j]) && i < j){
            j--;
        }
        if(tolower(s[i]) == tolower(s[j])){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "5?36@6?35";
    cout<<checkPalindrome(s);
}