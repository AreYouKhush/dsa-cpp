#include<bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    ios::sync_with_stdio(0), cin.tie(0);
    int cielNum = tickets[k];
    int time = 0;
    for(int i = 0; i < tickets.size(); i++){
        if(i <= k){
            time += tickets[i] >= cielNum ? cielNum : tickets[i];
        }else {
            time += tickets[i] >= cielNum - 1 ? cielNum - 1 : tickets[i];
        }
    }
    return time;
}

int main(){
    vector<int> inp = {2,3,4,56,3,45,56,6,34,45,2};
    cout<<timeRequiredToBuy(inp, 3);
}