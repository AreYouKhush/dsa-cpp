#include<bits/stdc++.h>
using namespace std;

// O(nlongn + nlogk)
bool cmp(pair<int, double>& a, pair<int, double>& b) {
    return a.second < b.second;
}

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<int, double>> pairs;
    
    for(int i = 0; i < quality.size(); i++) {
        pairs.push_back({quality[i], wage[i]*1.0/quality[i]});
    }
    sort(pairs.begin(), pairs.end(), cmp);

    for(int i = 0; i < pairs.size(); i++) {
        cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
    }

    priority_queue<int> pq; // quality
    int total_quality = 0;
    double res = DBL_MAX;

    for(int i = 0; i < pairs.size(); i++) {
        pq.push(pairs[i].first);
        total_quality += pairs[i].first;

        if(pq.size() > k) {
            total_quality -= pq.top();
            pq.pop();
        }

        if(pq.size() == k) {
            res = min(res, total_quality * pairs[i].second);
        }

    }

    return res;
}

int main() {
    vector<int> quality = {3,2,4,2,1,4,5};
    vector<int> wage = {70,50,30,30,80,20,40};
    cout<<mincostToHireWorkers(quality, wage, 5);
    return 0;
}