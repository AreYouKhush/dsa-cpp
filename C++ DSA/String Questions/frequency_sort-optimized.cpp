#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    Where 'N' is length of the string
*/

string sortByFrequency(int n, string s){
    string ans = "";
    set<pair<int, char>> ch;
    // Sort the string to make charcaters together.
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++){
        int j = i;
        while (j < n && s[i] == s[j]){
            j++;
        }
        // Store frequency and character.
        ch.insert({-(j - i), s[i]});
        i = j - 1;
    }
    for (auto it = ch.begin(); it != ch.end(); it++){
        // Concatenating it->first number of it->second character to string.
        ans += string(abs(it->first), it->second);
    }
    return ans;
}

int main(){
    string s = "tree";
    int n = s.size();
    cout<<sortByFrequency(n, s);
}