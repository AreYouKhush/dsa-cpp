#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        int ans = 0;
        bool positive = true;
        bool op = false;
        for(int i = 0; i < s.size(); i++){
            if(ans >= INT_MAX/10 && positive){
                return INT_MAX;
            }else if(!positive && -ans <= INT_MIN/10){
                return INT_MIN;
            }
            if(isdigit(s[i])){
                ans = ans*10 + ((int)s[i]-'0');
            }else if(s[i] == ' '){
                continue;
            }else if(s[i] == '-' && positive && !op){
                positive = false;
                op = true;
            }else if(s[i] == '+' && !op){
                op = true;
                continue;
            }else{
                break;
            }
        }
        return positive ? ans : -ans;
    }

    int main(){
        cout<<myAtoi("00000-42a1234");
    }