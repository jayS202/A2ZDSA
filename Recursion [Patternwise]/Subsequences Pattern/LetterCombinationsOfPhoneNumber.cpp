// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// TC - O(n*(k^n)), SC - O(n*(k^n))

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void backtrack(int ind, string digits, unordered_map<char, string> &phoneMap, vector<string> &ans, string current){
            if(ind == digits.size()){
                ans.push_back(current);
                return;
            }
            
            string letters = phoneMap[digits[ind]];
            for(char letter: letters){
                current.push_back(letter);
                backtrack(ind+1, digits, phoneMap, ans, current);
                current.pop_back();
            }
        }
    
        vector<string> letterCombinations(string digits){
            if(digits.empty())return {};
            vector<string> ans;
            string current;
            unordered_map<char, string> phoneMap = {
              {'2',"abc"},{'3', "def"}, {'4', "ghi"}, {'5', "jkl"},{'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} 
            };
            backtrack(0, digits, phoneMap, ans, current);
            return ans;
        }
};

int main()
{
    Solution solution;
    string digits = "23";
    vector<string> combinations = solution.letterCombinations(digits);

    // Print the result.
    for (const string &combo : combinations) {
        cout << combo << " ";
    }
    return 0;
}
