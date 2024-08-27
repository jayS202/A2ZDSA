// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// SC - O(N) TC - O(1)

#include<bits/stdc++.h>
using namespace std;

string largestOddNum(string s){
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        int number = s[i]-'0';
        if(number%2==1){
            track = i;
            break;
        }
    }
    if(track == -1){
        return "";
    }
    return s.substr(0,track+1);
}

int main()
{
    string s = "35427";
    string num = largestOddNum(s);
    cout<<num<<"\n";
    return 0;
}

// The above code can also be return as below:

#include<bits/stdc++.h>
using namespace std;

string largestOddNum(string s){
    int n = s.size();
    int track = -1;
    for(int i=n-1;i>=0;i--){
        if((s[i]-'0')%2==1){
            return s.substr(0,i+1);
        }
    }
    return "";
}

int main()
{
    string s = "52";
    string num = largestOddNum(s);
    cout<<num<<"\n";
    return 0;
}
