// Problem Statement: Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// TC - 𝑂(𝑛), where 𝑛 is the length of the strings s and t.
// SC - O(2n), where 𝑛 is the length of the strings s and t.
// Using 2 unordered_map
#include<bits/stdc++.h>
using namespace std;

bool Isomorphic(string s, string t){
    unordered_map<char, char> mpp_stot;
    unordered_map<char, char> mpp_ttos;
    if(s.size()!=t.size()) return false;
    
    for(int i=0;i<s.size();i++){
        if(mpp_stot.find(s[i])!=mpp_stot.end() && mpp_stot[s[i]]!=t[i]) return false;
        if(mpp_ttos.find(t[i])!=mpp_ttos.end() && mpp_ttos[t[i]]!=s[i]) return false;
        
        mpp_stot[s[i]] = t[i];
        mpp_ttos[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "badc";
    string t = "kikp";
    (Isomorphic(s,t)) ? cout<<"Isomorphic": cout<<"Not Isomorphic";
    return 0;
}

// TC - 𝑂(𝑛), where 𝑛 is the length of the strings s and t.
// SC - O(k), where 𝑘 is the number of unique characters in the strings s and t.
// Using single unordered_map
#include<bits/stdc++.h>
using namespace std;

bool Isomorphic(string s, string t){
    unordered_map<char, char> mpp;
    if(s.size()!=t.size()) return false;
    
    for(int i=0;i<s.size();i++){
        if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]!=t[i]) return false;
        if(mpp.find(t[i])!=mpp.end() && mpp[t[i]]!=s[i]) return false;
        
        mpp[s[i]] = t[i];
        mpp[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "foo";
    string t = "bar";
    (Isomorphic(s,t)) ? cout<<"Isomorphic": cout<<"Not Isomorphic";
    return 0;
}

// TC - 𝑂(𝑛), where 𝑛 is the length of the strings s and t.
// SC - O(m), where m is the number of unique characters in the strings s and t.
#include<bits/stdc++.h>
using namespace std;

bool isomporphic(string s, string t){
    vector<int> IndexS(200, 0);
    vector<int> IndexT(200, 0);
    
    if(s.size()!=t.size())return false;
    
    for(int i=0;i<s.size();i++){
        if(IndexS[s[i]]!=IndexT[t[i]])return false;
        
        IndexS[s[i]] = i+1;
        IndexT[t[i]] = i+1;
    }
    return true;
}

int main()
{
    string s = "paper";
    string t = "title";
    bool res = isomporphic(s,t);
    (res)?cout<<"isomporphic":cout<<"Not isomporphic";
    return 0;
}
