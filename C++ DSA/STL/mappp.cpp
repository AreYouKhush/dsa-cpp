#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> m;

    m[1] = "love";
    m[2] = "babbar";
    m[69] = "DApps";
    m[3] = "DSA";
    m[4] = "Web3";

    m.insert({5, "Bheem"});

    cout<<"Before Erase: "<<endl;

    for(auto i:m){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    cout<<"Finding 69: "<<m.count(69)<<endl;

    m.erase(69);
    cout<<"After Erase: "<<" ";
    for(auto i:m){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    auto it = m.find(3);

    cout<<endl;
    for(auto i = it; i != m.end(); i++){
        cout<<(*i).first<<" : "<<(*i).second<<endl;
    }
}