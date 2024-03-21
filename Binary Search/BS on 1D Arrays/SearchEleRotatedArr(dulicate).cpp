// Search Element in Rotated Sorted Array II
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// TC - O(log N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==target)return true;
        // if duplicate exists shift low to low + 1 and high to high - 1 
        if(arr[mid]==arr[low]&&arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
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
    return false;
}

int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = arr.size();
    int target = 10;
    bool ans = searchInARotatedSortedArrayII(arr, n, target);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
