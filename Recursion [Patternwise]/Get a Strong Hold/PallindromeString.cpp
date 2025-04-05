#include<bits/stdc++.h>
using namespace std;

// TC - O(N/2) SC - O(1)
bool pallindrome(string str){
    int n = str.size();
    int i = 0;
    while(i<=n/2){
        cout<<str[i]<<" "<<str[n-1-i]<<"\n";
        if(str[i]!=str[n-1-i]) return false;
        i++;
    }
    return true;
}
 
// TC - O(N/2), SC - O(1)
bool pallindrome(string str, int i, int n){
    if(i>=n/2){
        return true; 
    }
    cout<<str[i]<<" "<<str[n-1-i]<<"\n";
    if(str[i]!=str[n-1-i])return false;
    return pallindrome(str, i+1, n);
}
 

int main()

{
    string str = "ABCDCA";
    int n = str.size();
    cout<< ((pallindrome(str,0,n))? "pallindrome": "Not pallindrome");
    return 0;
}
