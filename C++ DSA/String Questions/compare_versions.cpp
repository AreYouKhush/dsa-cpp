#include<bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    int i = 0;
    int j = 0;
    int v1 = 0, v2 = 0;
    while(i < version1.size() && j < version2.size()) {
        string n1 = "", n2 = "";
        while(i < version1.size() && version1[i] != '.'){
            n1 += version1[i];
            i++;
        }
        while(j < version2.size() && version2[j] != '.'){
            n2 += version2[j];
            j++;
        }
        v1 = stoi(n1);
        v2 = stoi(n2);
        if(v1 > v2) return 1;
        else if(v1 < v2) return -1;
        i++;
        j++;
    }
    
    while(i < version1.size()){
        string n1 = "";
        while(i < version1.size() && version1[i] != '.'){
            n1 += version1[i];
            i++;
        }
        v1 = stoi(n1);
        if(v1 > 0) return 1;
        i++;
    }
    while(j < version2.size()){
        string n2 = "";
        while(j < version2.size() && version2[j] != '.'){
            n2 += version2[j];
            j++;
        }
        v2 = stoi(n2);
        if(v2 > 0) return -1;
        j++;
    }
    return 0;
}

int main() {
    string v1 = "1.01.2.13";
    string v2 = "1.001.2.12";
    int res = compareVersion(v1, v2);
    cout<<(res == 0 ? "They are same!" : (res == 1 ? "V1 is newer." : "V2 is newer."));
}