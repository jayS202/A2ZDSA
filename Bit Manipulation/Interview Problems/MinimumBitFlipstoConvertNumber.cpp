// Problem Statement: A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

// TC -  O(log(max(start, goal))), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findSetBits(int n){
    int cnt = 0;
    while(n!=0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int MinimumBitFlips(int start, int goal){
    int Xor = start ^ goal;
    int res = findSetBits(Xor);
    return res;
}

int main()
{
    int start = 3;
    int goal = 4;
    cout<<MinimumBitFlips(start, goal);
    return 0;
}
