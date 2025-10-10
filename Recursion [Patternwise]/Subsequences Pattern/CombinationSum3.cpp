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

// Using the Pick and Not pick approach

// ✨ Intuitive Explanation: Combination Sum III
// In this pick/not-pick recursion:
// - The Pick branch says:
// "Let’s include arr[ind] in the current combination.
// Reduce the target by arr[ind], and move to the next index to avoid reusing the same number."
// - The Not-pick branch says:
// "Okay, I’ve explored all combinations that include arr[ind].
// Now skip it and try combinations that don’t include this number."
// - The Base case checks:
// "If I’ve reached the end of the array, and the target is zero,
// and I’ve picked exactly n numbers — then this is a valid combination."

// 🧠 Why This Works
// - The array {1,2,3,4,5,6,7,8,9} is fixed and sorted.
// - Each number is used at most once.
// - The recursion explores all subsets of size n whose sum is target.
// - By checking ds.size() == n and target == 0, you ensure only valid combinations are added.

#include<bits/stdc++.h>
using namespace std;

void combi(int ind, int n, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(ind == arr.size()){
        if(target == 0 && ds.size()==n){
            ans.push_back(ds);   
        }
        return;
    }
    
    // Take
    ds.push_back(arr[ind]);
    combi(ind+1, n, target-arr[ind], arr, ans, ds);
    ds.pop_back();
    
    //Not Take
    combi(ind+1, n, target, arr, ans, ds);
}

vector<vector<int>> combinationSum3(int n, int target){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    vector<int> ds;
    int ind = 0;
    combi(ind, n, target, arr, ans, ds);
    return ans;
}

int main(){
    int n = 3;
    int target = 9;
    vector<vector<int>> res = combinationSum3(n, target);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
