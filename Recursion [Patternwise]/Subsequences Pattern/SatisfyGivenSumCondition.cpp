// Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition.

// You are given an array of integers nums and an integer target.
// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

// Approach 1: Using Recursion
// TC - O(2^N), SC - O(n)
#include<bits/stdc++.h>
using namespace std;

int implement(int ind, int* arr, int k, int n, int mini, int maxi){
    if(ind == n){
        if(maxi+mini <= k){
            return 1;
        }
        return 0;
    }
    
    int prev_max = maxi;
    int prev_min = mini;
     
    // Take
    maxi = max(maxi, arr[ind]);
    mini = min(mini, arr[ind]);
    int l = implement(ind+1, arr, k, n, mini, maxi);
    
    // Not Take
    
    maxi = prev_max;
    mini = prev_min;
    int r = implement(ind+1, arr, k, n, mini, maxi);
    
    return l+r;
}

void getAllSubSumK(int *arr, int k, int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    cout<<implement(0, arr, k, n, mini, maxi)-1;
}

int main()
{
    int arr[] = {3,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 9;
    getAllSubSumK(arr, k, n);
    return 0;
}
