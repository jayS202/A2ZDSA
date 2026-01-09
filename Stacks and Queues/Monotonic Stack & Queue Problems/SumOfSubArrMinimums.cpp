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


// Optimal Approach
// TC - O(N), SC-O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;
        stack<int> pst;
        long long total = 0;
        long long MOD = 1'000'000'007;
        
        // NSE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // PSE
        for(int i=0;i<n;i++){
            while(!pst.empty() && arr[pst.top()] >= arr[i]) pst.pop();
            pse[i] = pst.empty() ? -1 : pst.top();
            pst.push(i); 
        }

        for(int i=0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            // total = (total + (left*right*arr[i]*1ll)%MOD ) % MOD;
            long long contrib = ((left % MOD)*(right % MOD))%MOD;
            contrib = (contrib * (arr[i]%MOD))%MOD;
            total = (total + contrib)%MOD;
        }
        return (int)total; 
    }
};


