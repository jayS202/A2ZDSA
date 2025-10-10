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


// Pick and Not pick approach - Just improving the method to remove the duplicates at the first element (current element)

// ✨ Intuitive Explanation: Subset Sum II

// In this pick/not-pick recursion:

// - Pick branch says:
// "Let’s include arr[ind] in the current subset and explore all combinations that follow it."

// - Not-pick branch says:
// "Okay, I’ve explored all subsets that include arr[ind].
// Now, I want to skip every other duplicate of arr[ind] so I don’t repeat the same subset structure again.
// Let’s jump to the next new unique number and start fresh from there."


// 🔍 Why This Works

// - By sorting the array first, duplicates are grouped together.
// - The pick path allows duplicates to be included naturally.
// - The not-pick path uses a while loop to skip over all adjacent duplicates, ensuring we don’t generate the same subset multiple times.

#include<bits/stdc++.h>
using namespace std;

void getAllSubsets(int ind, vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds, int n){
    if(ind>=n){
        ans.push_back(ds);
        return;
    }
    
    ds.push_back(arr[ind]);
    getAllSubsets(ind+1, ans, arr, ds, n);
    ds.pop_back();
    
    int next = ind+1;
    while(next<n && arr[ind]==arr[next])next++;
    
    getAllSubsets(next, ans, arr, ds, n);
}

vector<vector<int>> Subset2(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    int ind = 0;
    getAllSubsets(ind, ans, arr, ds, n);
    return ans;
}

int main(){
    vector<int> arr = {4,4,4,1,4};
    int n = arr.size();
    vector<vector<int>> res = Subset2(arr, n);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    } 
    return 0;
}
