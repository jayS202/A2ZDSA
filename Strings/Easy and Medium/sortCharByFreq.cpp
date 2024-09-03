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

// TC - O(N log N) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

string sortByFrequency(string s){
    unordered_map<char,int> ans;
    string res = "";
    
    // Frequency Counting
    for(char a: s){
        ans[a]++;
    }
    
    // Storing Pairs in Vector
    vector<pair<char,int>> freqVec(ans.begin(),ans.end());

    // Sorting using lamnda function 
    sort(freqVec.begin(),freqVec.end(),[](pair<char,int> &a, pair<char,int> &b){
        return a.second>b.second;
    });

    // Buid the Result
    for(auto it: freqVec){
        res.append(it.second, it.first);
    }

    return res;
}

int main()
{
    string s = "tree";
    string res = sortByFrequency(s);
    cout<<res;
    return 0;
}
