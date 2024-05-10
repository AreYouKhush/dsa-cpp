#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                double frac = arr[i]/(double)arr[j];
                pair<int, int> pr = {arr[i], arr[j]};
                pq.push({frac, pr});
            }
        }

        k = pq.size() - k;
        vector<int> res;
        while(!pq.empty()) {
            if(k == 0) {
                res = {pq.top().second.first, pq.top().second.second};
            }
            // cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            pq.pop();
            k--;
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1,2,3,5,7};
    vector<int> res = obj.kthSmallestPrimeFraction(arr, 5);
    cout<<res[0]<<" "<<res[1]; 
}