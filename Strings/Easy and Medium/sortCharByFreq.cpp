// Problem Statement - Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// TC - O(N^2) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

string sortByFrequency(string str){
    unordered_map<char,int> ans;
    string s = "";
    for(char a:str){
        ans[a]++;
    }
    
    while(!ans.empty()){
        char ch = '\0';
        int cnt = 0;
        for(auto it: ans){
            if(it.second>cnt){
                ch = it.first;
                cnt = it.second;
            }
        }
        s.append(cnt,ch);
        ans.erase(ch);
    }
    return s;
}

int main()
{
    string str = "tree";
    string res = sortByFrequency(str);
    cout<<res;
    return 0;
}
