//Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Brute Force - Take/Not Take using Set to store ds.
// TC - O(2^N), SC - O(2^N * N)
#include<bits/stdc++.h>
using namespace std;

void implement(int ind, int sum, vector<int> &ds, vector<int> &arr, int k, set<vector<int>> &ans){
    if(ind == arr.size()){
        if(sum == k){
            ans.insert(ds);
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum += arr[ind];
    implement(ind+1, sum, ds, arr, k, ans);
    
    ds.pop_back();
    sum -= arr[ind];
    implement(ind+1, sum, ds, arr, k, ans);
}

set<vector<int>> getAllSubSumK(vector<int> &arr, int k){
    vector<int> ds;
    set<vector<int>> ans;
    sort(arr.begin(), arr.end());
    implement(0, 0, ds, arr, k, ans);
    return ans;
}

int main()
{
    vector<int> arr = {2,5,2,1,2};
    int k = 5;
    set<vector<int>> res = getAllSubSumK(arr, k);
    for(auto it: res){
        for(int num: it){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// Optimal Approach
// TC - , SC - 
