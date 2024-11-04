// Problem Statement: Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
// If both the strings have equal count of distinct subsequence then return str1.

// TC - O(2^N), SC - O(2^N)
#include<bits/stdc++.h>
using namespace std;

int implement(int ind, string &ds, string str, int n, unordered_map<string, int> &mpp){
    if(ind == n){
        if(mpp.find(ds)==mpp.end() && ds != ""){
            mpp[ds] = 1;
            // cout<<ds<<"\n";
            return 1;
        }
        return 0;
    }
    
    // Take
    ds.push_back(str[ind]);
    int l = implement(ind+1, ds, str, n, mpp);
    
    // Not Take
    ds.pop_back();
    int r = implement(ind+1, ds, str, n, mpp);
    
    return l + r;
}

string getAllSubSumK(string str1, string str2, int n){
    unordered_map<string,int> mpp1;
    string ds1;
    int s1 = implement(0, ds1, str1, n, mpp1);
    
    unordered_map<string,int> mpp2;
    string ds2;
    int s2 = implement(0, ds2, str2, n, mpp2);
    return (s1>=s2)? str1 : str2;
}

int main()
{
    string str1 = "wvpwo";
    string str2 = "nypsv";
    int n = str1.size();
    cout<<getAllSubSumK(str1, str2, n);
    return 0;
}
