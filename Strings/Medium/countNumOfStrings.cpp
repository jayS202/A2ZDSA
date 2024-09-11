// Problem Statement: Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

// TC - O(N) where N is the length of the string
// SC - O(k) where K is the number of distinct element
#include <bits/stdc++.h>
using namespace std;

int countSubstr(string s, int k){
    int left = 0, right = 0;
    int count = 0;
    unordered_map<char,int> freqMap;
    while(right<s.size()){
        
        freqMap[s[right]]++;
        
        while(freqMap.size()>k){
            freqMap[s[left]]--;
            if(freqMap[s[left]]==0){
                freqMap.erase(s[left]);
            }
            left++;
        }
        
        count += right-left+1;
        right++;
    }
    return count;
}

int substrCount(string s, int k){
    int ans = countSubstr(s, k) - countSubstr(s, k-1); 
    return ans;
}

int main()
{
    string s = "pqpqs";
    int k = 2;
    int res = substrCount(s,k);
    cout<<res;
    return 0;
}
