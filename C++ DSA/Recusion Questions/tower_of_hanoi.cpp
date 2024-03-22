#include<bits/stdc++.h>
using namespace std;

/*
    1. We have three rods with disks
    2. Take the disks from rod A to rod B
    3. Largest disk at the bottom and the smaller on top
    4. Can move only once at a time
    5. Cannot put bigger disk on smaller disk
*/

void towerOfHanoi(int n, string from_rod, string to_rod, string aux_rod) { 
    if (n == 0) { 
        return; 
    } 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl; 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 

int main(){
    towerOfHanoi(5, "start", "end", "aux");
}