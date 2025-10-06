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

// Sorting Array using Recursion
// We'll use a simple logic:
// 1. Remove the last element.
// 2. Recursively sort the remining array.
// 3. Insert the last element into its correct position in the sorted Array.

// Approach:
// 1. sortArray(vector<int> &arr)
// - Sorts the array recursively.
// - Base case: If only one element -> already sorted

// 2. insert(vector<int> &arr, int temp)
// - Insert an element temp into the sorted array arr.

// Code:
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr, int temp){
    if(arr.size()==0 || arr.back()<=temp){
        arr.push_back(temp);
        return;
    }
    
    int val = arr.back();
    arr.pop_back();
    
    insert(arr, temp);
    
    arr.push_back(val);
}

void sortArray(vector<int> &arr){
    if(arr.size()==1)return;
    
    int temp = arr.back();
    arr.pop_back();
    
    sortArray(arr);
    
    insert(arr, temp);
}

int main(){
    vector<int> arr = {3, 4, 2, 5, 1, 6};
    sortArray(arr);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}
