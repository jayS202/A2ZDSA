// // Problem Statement:
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

// TC - O(N^4) SC - O(N)
#include <bits/stdc++.h>
using namespace std;

int BeautyString(string s){
    int count = 0;
    vector<string> poss;
    int n = s.size();
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            string str = s.substr(i,j-i);
            if(str.size()>2){
                poss.push_back(str);    
            }
        }
    }
    
    for(auto it: poss){
        cout<<it<<" : ";
        unordered_map<char,int> freqMap;
        int mini = it.size();
        int maxi = 0;
        for(char ch: it){
            freqMap[ch]++;
        }
        
        for(auto st: freqMap){
            cout<<"st.second: "<<st.second;
            if(st.second>maxi) maxi = st.second;
            if(st.second<mini) mini = st.second;
        }
        ((maxi - mini)<=0)?count += 0: count += maxi-mini;
    }
    return count;
}


int main()
{
    string s = "aabcbaa";
    int res = BeautyString(s);
    cout<<res;
    return 0;
}
