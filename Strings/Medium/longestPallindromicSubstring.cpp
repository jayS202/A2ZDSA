// Problem Statement - Given a string s, return the longest palindromic substring in s.


// TC - O(N^2) SC - O(1)
#include<bits/stdc++.h>
using namespace std;


// Expand Around Center method
string longestPalindrome(string s){
    int n = s.size();
    int max_len = 1;
    int start = 0, end = 0;

    // Odd Palindrome - "babad"
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--;
                r++;
            }else{
                break;
            }
        }
        int len = r - l - 1;
        
        if(len>max_len){
            max_len = len;
            start = l+1;
            end = r-1;
        }
    }
    
    // Even Pallindrome - "cbba"
    for(int i=0;i<n;i++){
        int l=i, r=i+1;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--;
                r++;
            }else{
                break;
            }
        }
        int len = r-l-1;
        if(len>max_len){
            max_len = len;
            start = l+1;
            end = r-1;
        }
    }
    
    return s.substr(start, max_len);
}

int main()
{
    string s = "cbba";
    string res = longestPalindrome(s);
    cout<<res;
    return 0;
}
