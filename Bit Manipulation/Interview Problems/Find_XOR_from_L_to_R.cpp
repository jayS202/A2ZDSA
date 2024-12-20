// Problem statement - You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Brute force
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    int n = 5;
    cout<<findXOR(n);
    return 0;
}

// Optimal Approach
// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){
    if(n%4==1)return 1;
    if(n%4==2)return n+1;
    if(n%4==3)return 0;
    else return n;
}

int main()
{
    int n = 5;
    cout<<findXOR(n);
    return 0;
}

// Problem Solution
// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){
    if(n%4==1)return 1;
    if(n%4==2)return n+1;
    if(n%4==3)return 0;
    else return n;
}

int main()
{
    int l = 4;
    int r = 8;
    int res = findXOR(l-1)^findXOR(r);
    cout<<res;
    return 0;
}
