// Problem Statement:

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
//  - Only numbers 1 through 9 are used.
//  - Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// TC - O(2^N), SC - O(k) for the recursion stack.
#include<bits/stdc++.h>
using namespace std;

void printAns(vector < vector < int >> & ans) {
  cout << "The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}


class Solution{
    public: 
        void CombinationSum3(int ind, int target, int n, vector<int> &ds, vector<vector<int>> &ans){
            if(ds.size()==n && target == 0){
                ans.push_back(ds);
                return;
            }
            
            if(ds.size()>n || target<0)return;
            
            for(int i=ind; i<=9; i++){
                ds.push_back(i);
                CombinationSum3(i+1, target-i, n, ds, ans);
                ds.pop_back();
            }
        }
    
        vector<vector<int>> Combination(int n, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            CombinationSum3(1, target, n, ds, ans);
            return ans;
        }
};

int main()
{
    Solution obj;
    int n = 3;
    int target = 7;
    vector < vector < int >> ans = obj.Combination(n, target);
    printAns(ans);
    return 0;
}
