// Problem Statement - A function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Better
// Time Complexity: 
// 𝑂(𝑁⋅𝑀), where N is the number of strings and 𝑀 is the length of the longest string.
// In the worst case, we are comparing every character of every string with the current prefix.

// Space Complexity: 
// 𝑂(1) additional space is used, apart from the input and output.
  
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> str){
    string prefix = str[0];
    for(int i=0;i<str.size();i++){
        while(str[i].find(prefix)!=0){
            prefix = prefix.substr(0,prefix.size()-1);
            if(prefix.empty())return "";
        }
    }
    return prefix;
}

int main()
{
    vector<string> str = {"flower","flow","flight"};
    string res = longestCommonPrefix(str);
    cout<<res<<"\n";
    return 0;
}

// Optimal
// Time Complexity: 
// 𝑂(𝑁⋅log⁡𝑁+𝑀), where 𝑁 is the number of strings, and 𝑀 is the average length of the strings. Sorting the strings takes 𝑂(𝑁⋅log⁡𝑁)
// and comparing the first and last strings takes 𝑂(𝑀).

// Space Complexity: 
// 𝑂(1) additional space, ignoring the space required for sorting the input list in-place.
  
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &str){
    sort(str.begin(),str.end());
    int n = str.size();
    string prefix = "";
    for(int i=0;i<min(str[0].size(),str[n-1].size());i++){
        if(str[0][i]!=str[n-1][i]){
            return prefix;
        }
        prefix += str[0][i];
    }
    return prefix;
}

int main()
{
    vector<string> str = {"flower","flow","flight"};
    string res = longestCommonPrefix(str);
    cout<<res<<"\n";
    return 0;
}
