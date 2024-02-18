#include<iostream>
#include<set>
#include<bits/stdc++.h>
using namespace std;

// int main(){
//     set<int> s;

//     s.insert(5);
//     s.insert(5);
//     s.insert(5);
//     s.insert(8);
//     s.insert(2);
//     s.insert(4);
//     s.insert(2);
//     s.insert(3);

//     cout<<"Size of set: "<<s.size()<<endl;

//     for(int i:s){
//         cout<<i<<" ";
//     }cout<<endl;

//     set<int>::iterator it = s.begin();
//     it++;

//     s.erase(it);
//     for(int i:s){
//         cout<<i<<" ";
//     }cout<<endl;

//     cout<<"5 is present or not: "<<s.count(5)<<endl;

//     set<int>::iterator itr = s.find(5);
    
//     for(auto it = itr; it != s.end(); it++){
//         cout<<*it<<" ";
//     }cout<<endl;
// }

typedef pair<int, string> pairs;

int main(){
    set<pairs> s;
    pairs x = make_pair(3,"h");
    pairs y = make_pair(2,"s");
    pairs k = make_pair(1,"K");
    pairs a = make_pair(2,"a");
    s.insert(y);
    s.insert(x);
    s.insert(k);
    s.insert(a);
    for(auto &pr : s){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}