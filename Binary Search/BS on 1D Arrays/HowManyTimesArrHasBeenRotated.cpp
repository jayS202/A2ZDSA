// Find out how many times the array has been rotated
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

// TC - O(log N) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int mini = INT_MAX;
    int index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<mini){
                index = low;
                mini = arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                index = low;
                mini = arr[low];
            }
            low = mid + 1;
        }else{
            if(arr[low]<mini){
                index = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
