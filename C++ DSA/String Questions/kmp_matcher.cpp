#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
        // Kmp pie table
        int i = 0, j = 1;
        vector<int> pietable;
        pietable.push_back(0);
        while(j!=needle.size()){
            if(needle[i] == needle[j]){
                pietable.push_back(i+1);
                i++;
                j++;
            }else{
                if(i == 0){
                    pietable.push_back(0);
                    j++;
                }else{
                    i = pietable[i-1];
                }
            }
        }
        for(auto it: pietable){
            cout<<it<<" ";
        }
        cout<<endl;
        j = 0;
        int start = -1;
        for(i = 0; i < haystack.size(); i++){
            cout<<i<<" "<<j<<endl;
            cout<<haystack[i]<<" "<<needle[j]<<endl;
            cout<<"START: "<<start<<endl;
            if(haystack[i] == needle[j]){
                if(j == 0){
                    start = i;
                }
                j++;
                if(j == needle.size()){
                    return start;
                } 
            }else{
                if(j == 0){
                    j = 0;
                    start = -1;
                }else{
                    j = pietable[j-1];
                    if(haystack[i] == needle[j]){
                        start = i - j;
                        j++;
                    }else{
                        start = i - 1;
                    }
                }
            }
        }
        return -1;
    }

int main(){
    string s1 = "ababaabbbbababbaabaaabaabbaaaabbabaabbbbbbabbaabbabbbabbbbbaaabaababbbaabbbabbbaabbbbaaabbababbabbbabaaabbaabbabababbbaaaaaaababbabaababaabbbbaaabbbabb";
    string s2 = "abbabbbabaa";
    int p = strStr(s1, s2);
    cout<<p;
}