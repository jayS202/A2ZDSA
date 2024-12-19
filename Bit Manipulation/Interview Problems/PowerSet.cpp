// Problem Statement - Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// TC - N * (2^N), SC - (2^N) * N
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerset(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<(1<<n);i++){
        vector<int> list;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                list.push_back(arr[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = powerset(arr);
    for(auto it: ans){
        for(auto res: it){
            cout<<res<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
