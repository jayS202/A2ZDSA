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
// TC - O(2^N), SC - O(n+k)(with k being the number of unique combinations)
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void findCombination(int ind, int target, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            
            if(arr[i]>target)break;
            
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], ds, arr, ans);
            ds.pop_back();
        }
    }
  
    vector<vector<int>> combinationSum(vector<int> &arr, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        findCombination(0, target, ds, arr, ans);
        return ans;
    }
};

int main()
{
  Solution obj;
  vector < int > v {10,1,2,7,6,1,5};
  int target = 8;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }    
  return 0;
}


// Using the base Pick/Not-pick method with just a little improvement - Easy

// 🧠 Base Logic: Pick / Not-Pick
// At each index ind, you have two choices:
// 1. Pick the element (if it doesn’t exceed the target)
// 2. Not Pick the element — move forward and explore without it
// This creates all possible subsets (like subset recursion).

// ---

// 🚀 The Improvement: Skip Duplicates

// When not picking an element, we:
// Move the index ind forward to skip all identical elements.


// That means if we have sorted input like [1,1,2,5,6,7,10]
// and we decide not to take the first 1,
// we directly jump past all other 1s — no need to explore same combinations again.


// ---

// ⚙️ Key Steps
// 1. Sort the array → brings duplicates together
// 2. Pick current element if ≤ target → move to next index
// 3. Not pick → skip all identical elements before next recursion

// int next = ind + 1;
// while (next < arr.size() && arr[next] == arr[ind]) next++;
// findAllwithSum(arr, next, target, ds, ans);

// 4. Base condition: if ind >= n → push to answer only if target == 0

#include<bits/stdc++.h>
using namespace std;

void findAllwithSum(vector<int> &arr, int ind, int target, vector<int> &ds, vector<vector<int>> &ans){
    if(ind>=arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findAllwithSum(arr, ind+1, target-arr[ind], ds, ans);
        ds.pop_back();
    }
    
    int next = ind+1;
    while(next<arr.size() && arr[next]==arr[ind])next++;
    
    findAllwithSum(arr, next, target, ds, ans);
}

vector<vector<int>> findCombination(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    int ind = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    findAllwithSum(arr, ind, target, ds, ans);
    return ans;
}

int main(){
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = findCombination(arr, target);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

