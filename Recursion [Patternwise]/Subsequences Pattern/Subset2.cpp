// Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

// TC -  O(2^n) for generating every subset and O(k) to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).
// SC - O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
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
        void subset2(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
            ans.push_back(ds);
            
            for(int i = ind;i<arr.size();i++){
                // Skip duplicates
                if(i>ind && arr[i]==arr[i-1])continue;
                
                ds.push_back(arr[i]);
                subset2(i+1, ds, ans, arr);
                ds.pop_back();
            }
        }
        
        vector<vector<int>> subsetsWithDup(vector<int> &nums){
            sort(nums.begin(), nums.end()); // Sort to handle duplicates
            vector<vector<int>> ans;
            vector<int> ds;
            subset2(0, ds, ans, nums);
            return ans;
        }
};

int main()
{
    Solution obj;
    vector < int > nums = {1, 2, 2};
    vector < vector < int >> ans = obj.subsetsWithDup(nums);
    printAns(ans);
    return 0;
}
