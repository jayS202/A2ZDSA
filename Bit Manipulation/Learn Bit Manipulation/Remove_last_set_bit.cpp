// Remove the last set bit (Rightmost)

// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void RemoveLastSetBit(int n){
    int toggleBit = (n & (n-1));
    cout<<bitset<32>(toggleBit);
}

int main()
{
    int n = 20;
    RemoveLastSetBit(n);
    return 0;
}
