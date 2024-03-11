// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Optimal
// TC - O(N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    int n = a.size();
    int maxLen=0;
    unordered_map<int, int> mpp;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == 0){
            maxLen = i+1;
        }else if(mpp.find(sum)!=mpp.end()){
            maxLen =max(maxLen, i-mpp[sum]);
        }else{
            mpp[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}
