// Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.
// Note: A palindrome string is a string that reads the same backward as forward.

// Time Complexity: O( (2^n) *k*(n/2) )
// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isPalindrome(string s, int start, int end){
            while(start<=end){
                if(s[start++] != s[end--]){
                    return false;
                }
            }
            return true;
        }
        
        void implement(int ind, string s, vector<string> &ds, vector<vector<string>> &ans){
            if(ind == s.size()){
                ans.push_back(ds);
                return;
            }
            
            for(int i=ind;i<s.size();++i){
                if(isPalindrome(s, ind, i)){
                    ds.push_back(s.substr(ind, i-ind+1));
                    implement(i+1, s, ds, ans);
                    ds.pop_back();
                }
            }
        }
        
        vector<vector<string>> partition(string s){
            vector<vector<string>> ans;
            vector<string> ds;
            implement(0, s, ds, ans);
            return ans;
        }
};

int main()
{
  string s = "aabb";
  Solution obj;
  vector < vector < string >> ans = obj.partition(s);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}
