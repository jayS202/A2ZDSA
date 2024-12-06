// Probelm Statement: You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

// Examples :
// Input: n = 4
// Output: 5
// Explanation: For numbers from 1 to 4. For 1: 0 0 1 = 1 set bits For 2: 0 1 0 = 1 set bits For 3: 0 1 1 = 2 set bits For 4: 1 0 0 = 1 set bits Therefore, the total set bits is 5.
// Input: n = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.

// TC - O(log n), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int pow2(int n){
    int x = 0;
    while((1<<x) <= n){
        x++;
    }
    return x-1;
}

int countSetBits(int n){
    if(n==0)return 0;
    int x = pow2(n);
    int p2 = (1<<(x-1))*x;
    int remcol = n-(1<<x)+1;
    int res = p2+remcol+countSetBits(n-(1<<x));
    return res;
}

int main()
{
    int n = 8;
    cout<<countSetBits(n);
    return 0;
}
