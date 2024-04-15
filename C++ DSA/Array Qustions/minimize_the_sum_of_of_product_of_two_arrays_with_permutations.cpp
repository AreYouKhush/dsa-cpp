#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> inp1 = {6,1,9,5,4};
    vector<int> inp2 = {3,4,8,2,4};
    // sort(inp1.begin(), inp1.end());
    sort(inp2.begin(), inp2.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < inp1.size(); i++){
        sum += (inp1[i] * inp2[i]);
    }
    auto it = inp1.rbegin();
    while(it != inp1.rend()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    cout<<sum;
}