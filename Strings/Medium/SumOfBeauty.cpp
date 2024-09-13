// // Problem Statement:
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

// Brute Force
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

// Hashing
// TC - O(N^2) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int beautySum(string s){
    int Beauty = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        int freq[26] = {0};
        for(int j=i;j<n;j++){
            freq[s[j] - 'a']++;
            
            int mini = n, maxi = 0;
            for(int k=0;k<26;k++){
                if(freq[k]>0){
                    mini = min(mini, freq[k]);
                    maxi = max(maxi, freq[k]);
                }
            }
            
            Beauty += maxi - mini;
        }
    }
    return Beauty;
}


int main()
{
    string s1 = "aabcb";
    string s2 = "aabcbaa";
    
    cout << "Beauty sum of \"" << s1 << "\": " << beautySum(s1) << endl;  // Output: 5
    cout << "Beauty sum of \"" << s2 << "\": " << beautySum(s2) << endl;  // Output: 17
    return 0;
}


// We can also use unordered map to solve the problem.
// Mapping is comparitively faster than Hashing
// TC - O(N^2) SC-O(1)
#include<bits/stdc++.h>
using namespace std;

int beautySum(string s){
    int Beauty = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;

                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto it: freq){
                        mini = min(mini, it.second);
                        maxi = max(maxi, it.second);
                }

                Beauty += maxi-mini;
            }
        }
        return Beauty;
}


int main()
{
    string s1 = "aabcb";
    string s2 = "aabcbaa";
    
    cout << "Beauty sum of \"" << s1 << "\": " << beautySum(s1) << endl;  // Output: 5
    cout << "Beauty sum of \"" << s2 << "\": " << beautySum(s2) << endl;  // Output: 17
    return 0;
}

