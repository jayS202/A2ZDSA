// Problem Statement – Classic Zigzag Arrangement

// You are given an array of integers arr of size n.
// Rearrange the elements of arr in a zigzag fashion such that:

// arr[0] < arr[1] > arr[2] < arr[3] > arr[4] < arr[5] ...
// In other words:
// - At even indices (i % 2 == 0), the element at arr[i] should be less than the element at arr[i+1].
// - At odd indices (i % 2 == 1), the element at arr[i] should be greater than the element at arr[i+1].
// You may rearrange elements in-place and in O(n) time without sorting.

#include<bits/stdc++.h>
using namespace std;

// Version 1:
// TC - O(N), SC - O(1)
vector<int> zigzag(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        if((i%2==0 && arr[i]>arr[i+1])){
            swap(arr[i],arr[i+1]);
        }
        else if(i%2!=0 && arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}

// Similar to Version - Removed the Duplicate Code
vector<int> zigzag(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        if((i%2==0 && arr[i]>arr[i+1]) || (i%2!=0 && arr[i]<arr[i+1])){
            swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}


// Version - 3 (Slightly more wfficent as it is not using %)
vector<int> zigzag(vector<int> &arr, int n){
    bool expectLess = true;
    for(int i=0;i<n-1;i++){
        if(expectLess){
            if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
        }else{
            if(arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
        }
        expectLess = !expectLess;
    }
    return arr;
}

int main()
{
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};
    int n = arr.size();
    vector<int> res = zigzag(arr, n);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
