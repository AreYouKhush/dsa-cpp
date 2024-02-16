#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
// 	vector<vector<int>> ans;
// 	for(int i = 0; i < n - 2; i++){
// 		for(int j = 1; j < n - 1; j++){
// 			for(int k = 2; k < n; k++){
// 				if(i != j && j != k){
// 					if(arr[i] + arr[j] + arr[k] == K){
// 						ans.push_back({arr[i], arr[j], arr[k]});
// 					}
// 				}
// 			}
// 		}
// 	}
// 	if(ans.size() == 0){
//         ans.push_back({-1});
//     }return ans;
// }

#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

    set<vector<int>>hash;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                // if( arr[i] != arr[j] && arr[j] != arr[k]){
                    if(arr[i]+arr[j]+arr[k]==K){
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        hash.insert(temp);
                    }
                // }
            }
        }
    }

    vector<vector<int>> cool(hash.begin(), hash.end());
	if(hash.size() == 0){
        cool.push_back({-1});
    }else{
		return cool;
	}
}

int main()
{
    vector<int> vec = {10, 5, 5, 5, 2};
    int sum = 12;
    int n = vec.size();
    vector<vector<int>> ans = findTriplets(vec, n, sum);

    for (int i = 0; i < ans.size(); i++) {
        for ( auto it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    vec.clear();

    vec = {1, 2, 3, 1, 2, 3};
    sum = 6;
    n = vec.size();
    ans = findTriplets(vec, n, sum);

    for (int i = 0; i < ans.size(); i++) {
        for ( auto it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    vec.clear();
    ans.clear();

    vec = {1,2,3,4};
    sum = 11;
    n = vec.size();
    ans = findTriplets(vec, n, sum);

    for (int i = 0; i < ans.size(); i++) {
        for ( auto it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    vec.clear();
    ans.clear();

    vec = {1, 1, 2, 2, 1, 1};
    sum = 4;
    n = vec.size();
    ans = findTriplets(vec, n, sum);

    for (int i = 0; i < ans.size(); i++) {
        for ( auto it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    vec.clear();
    ans.clear();
    return 0;
}