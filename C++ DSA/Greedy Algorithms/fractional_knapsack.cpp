#include <bits/stdc++.h> 
using namespace std;

/*
    Fractional Knapsack:- (profit or value) / (weight)
*/

bool cmp(vector<double>& a, vector<double>& b){
    return a[2] > b[2];
}

double maximumValue1(vector<pair<int, int>>& items, int n, int w){
    vector<vector<double>> ratio;
    for(auto it: items){
      ratio.push_back({(double)it.first, (double)it.second, it.second/(double)it.first});
    }
    sort(ratio.begin(), ratio.end(), cmp);
    double finalValue = 0;
    int currentWeight = 0;
    for(int i = 0; i < ratio.size(); i++){
        if(w >= ratio[i][1] + currentWeight){
            currentWeight += ratio[i][0];
            finalValue += ratio[i][1];
        }else{
            int remain = w - currentWeight;
            finalValue += (ratio[i][1]/(double)ratio[i][0])*(double)remain;
            break;
        }
    }
    for(auto it: ratio){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
    return finalValue;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.second/(double)a.first > b.second/(double)b.first;
}

int fractionalKnapsack(vector<pair<int, int>>& items, int totalItems, int weight){
    sort(items.begin(), items.end(), cmp2);
    double finalValue = 0;
    int currentWeight = 0;
    for(int i = 0; i < items.size(); i++){
        if(weight >= items[i].first + currentWeight){
            currentWeight += items[i].first;
            finalValue += items[i].second;
        }else{
            int remain = weight - currentWeight;
            finalValue += (items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    for(auto it: items){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return finalValue;
}

int main(){ 
    vector<pair<int, int>> items = {{50,40},{40,50},{90,25},{120,100},{10,30},{200,45}};
    int totalItems = items.size();
    int weight = 200;
    double ans = fractionalKnapsack(items, totalItems, weight);
    // double ans = maximumValue1(items, totalItems, weight);

    cout<<"Total Value: "<<ans;
}