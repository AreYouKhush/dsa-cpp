#include<bits/stdc++.h>
using namespace std;

int setBits1(int N){
    int temp = N;
    int count = 0;
    while((temp&1) == 1){
        temp = temp >> 1;
        count++;
    }
    if(temp == 0){
        return N;
    }else{
        temp = temp | 1;
        while(count > 0){
            temp = temp << 1;
            temp = temp | 1;
            count--;
        }
    }
    return temp;
}

/*  
    Time Complexity : O(log N) 
    Space Complexity : O(1)
    where 'N' is the given input
*/
int setBits2(int N){
    int x=N;

    // Find the position of the east significant unset bit.
    while(x&1!=0)
    {
        x=x>>1;
    }

    // Check if there's any unset bit, if not return 'N'
    if(x==0)
    {
        return N;
    }
    
    // Set the least significant unset bit of ‘N’ to 1 and return.
    return N | (N+1);
}

/*  
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
int setBits3(int N){
    // Check if there's any unset bits.
    if((N & (N+1)) == 0)
        return N;
    
    // Set the least significant unset bit of ‘N’ to 1 and return.
    return N | (N+1);
}



int main(){
    int N = 7;
    cout<<setBits3(N);
}