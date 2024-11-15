// Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

// Brute Force
// TC - O(N*((2^N)+(2^N log (2^N)))),SC - O(2^N)
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void subset(int ind, vector<int> &ds, vector<int> &arr, int n, vector<int> &ans){
        if(ind == n){
            int sum = 0;
            for(auto it: ds){
                // cout<<it<<" ";
                sum+=it;
            }
            // cout<<" Sum: "<<sum<<"\n";
            ans.push_back(sum);
            return;
        }
        
        ds.push_back(arr[ind]);
        subset(ind+1, ds, arr, n, ans);
        
        ds.pop_back();
        subset(ind+1, ds, arr, n, ans);
    }
  
    vector<int> subsetSums(vector<int> &arr, int n){
        vector<int> ds;
        vector<int> ans;
        subset(0, ds, arr, n, ans);
        return ans;
    }
};

int main()
{
      vector<int> arr = {5,2,1};
      Solution ob;
      vector<int> ans = ob.subsetSums(arr, arr.size());
      sort(ans.begin(), ans.end());
      cout<<"The sum of each subset is "<<endl;
      for (auto sum: ans) {
        cout << sum << " ";
      }
      cout << endl;
      return 0;
}

// Optimal 
// TC - O((2^N)+(2^N log (2^N))), SC - O(2^N)
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void subset(int ind, vector<int> &arr, int n, vector<int> &ans, int sum){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        
        subset(ind+1, arr, n, ans, sum+arr[ind]);
        
        subset(ind+1, arr, n, ans, sum);
    }
  
    vector<int> subsetSums(vector<int> &arr, int n){
        vector<int> ans;
        subset(0, arr, n, ans, 0);
        return ans;
    }
};

int main()
{
      vector<int> arr = {5,2,1};
      Solution ob;
      vector<int> ans = ob.subsetSums(arr, arr.size());
      sort(ans.begin(), ans.end());
      cout<<"The sum of each subset is "<<endl;
      for (auto sum: ans) {
        cout << sum << " ";
      }
      cout << endl;
      return 0;
}
