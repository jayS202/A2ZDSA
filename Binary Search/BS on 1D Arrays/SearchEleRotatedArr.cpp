// Search Element in a Rotated Sorted Array
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// TC - O(log N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==target)return mid;
        //left is sorted
        if(arr[low]<=arr[mid]){
            //target is present on left
            if(arr[low]<=target && target<=arr[mid]){
                high = mid - 1;
            }
            //target is present on right
            else{
                low = mid + 1;
            }
        }
        //Right is sorted
        else{
            //target is present on Right
            if(arr[mid]<=target && target<=arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, target = 1;
    int ans = search(arr, n, target);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
