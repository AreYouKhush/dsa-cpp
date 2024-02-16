#include <iostream>
using namespace std;
int iteration = 0;
int search(int arr[], int len, int key){
    int mid, s, l;
    s = 0;
    l = len-1;
    while(s<=l){
        iteration++;
        
        // if(l==-1){
        //     return -1;
        // }

        mid = s + (l-s)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            l = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){
    int ar[100] = {22, 25, 31, 36, 40, 49, 55, 62, 74, 77};
    int n = 10;
    int key;
    // for(int i=0; i<n; i++){
    //     ar[i] = i+1;
    // }
    cout<<"Enter a key: ";
    cin>>key;
    int ans = search(ar, n, key);
    if(ans == -1){
        cout<<"Not found!"<<endl;
    }
    else{
        cout<<"Found at index number: "<<ans<<endl;
    }
    cout<<"Interations = "<<iteration;
    return 0;
}