// Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

// TC - O(n log n) SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

bool anagram(string str, string goal){
    if(str.size()!=goal.size()){
        return false;
    }
    
    sort(str.begin(),str.end());
    sort(goal.begin(),goal.end());
    
    if(str == goal){
        return true;
    }
    return false;
}

int main(){
    string str = "ACT";
    string goal = "CAT";
    bool res = anagram(str, goal);
    (res)?cout<<"anagram":cout<<"Not anagram";
    return 0;
}


// TC - O(N) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

bool anagram(string str, string goal){
    if(s.size()!=t.size())return false;
    vector<int> freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }

    for(int i=0;i<t.size();i++){
        freq[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0)return false;
    }

    return true;
}

int main(){
    string str = "RULES";
    string goal = "LESRT";
    bool res = anagram(str, goal);
    (res)?cout<<"anagram":cout<<"Not anagram";
    return 0;
}
