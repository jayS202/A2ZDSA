// Problem Statement: Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// TC - 𝑂(𝑛), where 𝑛 is the length of the strings s and t.
// SC - O(k), where 𝑘 is the number of unique characters in the strings s and t.
#include<bits/stdc++.h>
using namespace std;

bool isomporphic(string s, string t){
    unordered_map<char,char> mapST, mapTS;
    
    if(s.size()!=t.size())return false;
    
    for(int i=0;i<s.size();i++){
        if(mapST.find(s[i])!=mapST.end()){
            if(mapST[s[i]]!=t[i])return false;
        }else{
            mapST[s[i]]=t[i];
        }
        
        if(mapTS.find(t[i])!=mapTS.end()){
            if(mapTS[t[i]]!=s[i])return false;
        }else{
            mapTS[t[i]]=s[i];
        }
    }
    return true;
}

int main()
{
    string s = "foo";
    string t = "bar";
    bool res = isomporphic(s,t);
    (res)?cout<<"isomporphic":cout<<"Not isomporphic";
    return 0;
}

// TC - 𝑂(𝑛), where 𝑛 is the length of the strings s and t.
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

bool isomporphic(string s, string t){
    vector<int> IndexS(200, 0);
    vector<int> IndexT(200, 0);
    
    if(s.size()!=t.size())return false;
    
    int cnt = 1;
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
