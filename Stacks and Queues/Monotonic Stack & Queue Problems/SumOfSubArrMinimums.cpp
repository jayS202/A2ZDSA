// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Brute Force
// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int sumOfSubarrMin(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        int mini = arr[i];
        for(int j=i;j<n;j++){
            mini = min(mini, arr[j]);
            sum += mini;
        }
    }
    return sum;
}

int main(){
    vector<int> arr = {3,1,2,4};
    int res = sumOfSubarrMin(arr);
    cout<<res<<"\n";
    return 0;
}
