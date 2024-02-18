#include <bits/stdc++.h>
using namespace std;

void print(map<int, string> &m){
    cout << "Size: " << m.size() << endl;

    for (auto &pr : m){     // O(nlog(n))
        cout << pr.first << " " << pr.second << endl;
    }
}

int main(){
    map<int, string> m;
    m[1] = "abc";       //O(log(n))
    m[5] = "cdc";
    m[3] = "acd";
    m[5] = "cde";
    m.insert({4, "afg"});

    auto it = m.find(7);
    if(it == m.end()){
        cout<<"No value"<<endl;
    }else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    // m.erase(7);         // O(log(n)) deletes only the second
    // m.erase(it);        // O(log(n)) deletes the whole pair
    if(it != m.end())
        m.erase(it);
    
    m.clear();
    print(m);

}

// Unordered Maps differences:
//     1. Time Complexity Insertion and deletion TC: O(1) Average case
//     2. inbuilt implementation
//     3. valid keys datatypes