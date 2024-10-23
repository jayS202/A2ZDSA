// Problem Statement: Sort an Array using recursion

// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void insertArrAtPos(int *arr, int n){
    int key = arr[n-1];
    int j = n-2;
    
    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1]=key;
}


void recursiveSort(int *arr, int n){
    // Base case
    if(n == 1){
        return;
    }
    
    // Hypothesis
    recursiveSort(arr, n-1);
    
    // Induction
    insertArrAtPos(arr, n);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Before sort: "<<"\n";
    
    printArray(arr, n);
    
    recursiveSort(arr, n);
    
    cout<<"After Sort: "<<"\n";
    
    printArray(arr, n);
    return 0;
}
