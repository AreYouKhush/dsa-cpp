#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int ans = 0;
        if(x < 0){
            return false;
        }
        int m = x;
        while(m != 0){
            int cur = m % 10;
            if( ans > INT_MAX/10 || ans < INT_MIN/10){
                return false;
            }
            ans = (ans * 10) + cur;
            m /= 10;
        }
        return (ans == x);
    }
};

int main(){
    Solution s;
    if(s.isPalindrome(1010)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
}