// Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.

// TC - O(N), where N is the length of the string.
// SC -  O(N) due to the space needed for the concatenated string.
#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal){
    if(s.length()!=goal.length()){
        return false;
    }
    
    string concatenate = s + s;
    if(concatenate.find(goal)!=string::npos){
        return true;
    }
    return false;
}

int main()
{
    string s = "abcde";
    string goal = "abcde";
    bool result = rotateString(s, goal);
    cout << (result ? "true" : "false") << endl;  // Output: true
    return 0;
}
