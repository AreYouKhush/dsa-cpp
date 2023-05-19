#include <iostream>

using namespace std;

void getArr(int arr[], int size){
    cout<<"Enter the array: "<<"\n";
    for (int i=0; i<size; i++){
        cout<<"Enter a number: ";
        cin>>arr[i];
    }
    cout<<endl;
}

void display(int arr[], int n){
    cout<<"The array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// void swapAlternate(int arr[], int n){
//     for(int i=0,j=1;j<n&&i<n; i=i+2, j=j+2){
//         int temp;
//         temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
//     display(arr, n);
// }

void swapAlternate(int arr[], int n){
    for(int i = 0; i+1<n; i+=2){
        swap(arr[i], arr[i+1]);
    }
    display(arr, n);
}

int main()
{
    int n;
    cout<<"Enter the lenght of array: ";
    cin>>n;
    int arr[100];
    getArr(arr, n);
    display(arr, n);
    swapAlternate(arr, n);
    return 0;
}
