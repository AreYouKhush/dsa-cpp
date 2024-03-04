#include<bits/stdc++.h>
using namespace std;

int countSetBits1(int N){
    int setBits = 0;
    for(int i = 1; i <= N; i++){
        int temp = i;
        while(temp > 0){
            if((temp&1) == 1){
                setBits++; 
            }
            temp = temp >> 1; 
        }
    }
    return setBits;
}

int largestPowerOf2inRange(int N){
    int x = 0;
    while((1<<x) <= N){
        x++;
    }
    return x-1;
}

//Better approach
int countSetBits2(int N){
    if(N == 0){
        return 0;
    }
    int x = largestPowerOf2inRange(N);
    int btill2x = x * (1<<(x-1));
    int msb2xton = N - (1<<x) + 1;
    int rest = N - (1<<x);
    int ans = btill2x + msb2xton + countSetBits2(rest);
    return ans;
}

/*
   Time Complexity : O(Log(N))

   where 'N' is the number till which we have to count set bits..
*/
int countSetBits3(int N)
{
    // We have 'd' which is the size of repeating window.
    // We are using 'x' to run the loop Log(N) times which is equal to the number of bits in its binary representation.
    int d=2,ans=0,x=N;
    while(x)
    {

        // Using the Mathematical formula explained in the Approach.
        ans+=((N+1)/d)*(d/2) + max((N+1)%d-d/2,0);

        // Window size double every time we shift to the next left bit.
        d*=2;
        x/=2;
    }
    return ans;
}

int main(){
    int N = 2;
    cout<<countSetBits3(N);
}