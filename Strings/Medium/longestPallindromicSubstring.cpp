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


// With a common function

#include<bits/stdc++.h>
using namespace std;

string expandAroundCenter(string s, int left, int right){
    int n = s.size();
    while(left>=0 && right<n){
        if(s[left]==s[right]){
            left--;
            right++;
        }else{
            break;
        }
    }
    int len = right - left - 1;
    int start = left + 1;
    return s.substr(start, len);
}

string longestPalindrome(string s){
    string longest;
    int n = s.size();
    for(int i=0;i<n;i++){
        string s1 = expandAroundCenter(s,i,i);
        if(s1.size()>longest.size()){
            longest = s1;
        }
        
        string s2 = expandAroundCenter(s, i, i+1);
        if(s2.size()>longest.size()){
            longest = s2;
        }
        
    }
    return longest;
}

int main()
{
    string s = "babad";
    string res = longestPalindrome(s);
    cout<<res;
    return 0;
}
