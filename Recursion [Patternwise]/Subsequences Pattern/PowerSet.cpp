// Problem Statement: Given a string, find all the possible subsequences of the string.

// Using Bit Manipulation
// TC -  O(2^n * n), SC - O(n)
#include<bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    int len = s.length();
    for(int num=0;num<(1<<len);num++){
        string sub = "";
        for(int i=0;i<len;i++){
            if((num & (1<<i))!=0){
                sub += s[i];
            }
        }
        ans.push_back(sub);
    }
    return ans;
}

int main()
{
    string s = "abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}
    return 0;
}

// Using Recursion
// TC - O(2^n),SC - O(n)
#include<bits/stdc++.h>
using namespace std;

void solve(int ind, string s, string f){
    if(ind == s.length()){
        cout<<f<<" ";
        return;
    }
    
    // Take
    f = f+s[ind];
    solve(ind+1, s, f);
    
    // Not Take
    f.pop_back();
    solve(ind+1, s, f);
}

int main()
{
    string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
    return 0;
}
