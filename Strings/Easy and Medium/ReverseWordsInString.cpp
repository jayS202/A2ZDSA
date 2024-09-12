// Problem Statement

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.

// TC - O(N) SC-O(1)
#include <bits/stdc++.h>
using namespace std;

string reverseString(string s){
    int n = s.size();
    int pos = n-1;
    string temp = "";
    while(pos>=0){
        
        while(pos>=0 && s[pos]==' '){
            pos--;
        }
        int end = pos;
        
        while(pos>=0 && s[pos]!=' '){
            pos--;
        }
        
        if(end>=0){
            temp += s.substr(pos+1,end-pos)+" "; 
        }
    }
    if(!temp.empty()){
        temp.pop_back();
    }
    return temp;
}

int main()
{
    string s = "the sky is blue  ";
    string res = reverseString(s);
    cout<<res;
    return 0;
}
