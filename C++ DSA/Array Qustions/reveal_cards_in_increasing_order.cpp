#include<bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end()); // Sort the deck in increasing order
    
    int n = deck.size();
    vector<int> result(n);
    deque<int> indices;
    
    for (int i = 0; i < n; i++) {
        indices.push_back(i); // Initialize deque with indices 0, 1, 2, ..., n-1
    }
    
    for (int card : deck) {
        int idx = indices.front(); // Get the next available index
        indices.pop_front(); // Remove the index from the front
        result[idx] = card; // Place the card in the result array
        if (!indices.empty()) {
            indices.push_back(indices.front()); // Move the used index to the end of deque
            indices.pop_front(); // Remove the index from the front
        }
    }
    
    return result;
}

int main(){
    vector<int> inp = {2,3,4,56,3,45,56,6,34,45,2};
    vector<int> ans = deckRevealedIncreasing(inp);
    for(auto it: ans){
        cout<<it<<" ";
    }
}