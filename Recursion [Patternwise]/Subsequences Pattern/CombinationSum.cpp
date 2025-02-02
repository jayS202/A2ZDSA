// Problem Statement:
// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void findCombination(int ind, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
            // Base case
            if(ind == arr.size()){
                if(target == 0){
                    ans.push_back(ds);
                }
                return;
            }
            
            // take 
            if(arr[ind]<=target){
                ds.push_back(arr[ind]);
                findCombination(ind, target-arr[ind], ds, ans, arr);
                ds.pop_back();
            }
            
            // Not-take
            findCombination(ind+1, target, ds, ans, arr);
        }
    
    public:
        vector<vector<int>> combinationSum(vector<int> &v, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findCombination(0, target, ds, ans, v);
            return ans;
        }
};

int main()
{
  Solution obj;
  vector < int > v {2,3,6,7};
  int target = 7;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }    
  return 0;
}
