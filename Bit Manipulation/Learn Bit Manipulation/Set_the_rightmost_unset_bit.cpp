// Problem Statement - Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int setTheRightmostUnsetBit(int n){
    if((n&(n+1)) == 0){
        return n;
    }
    
    n = (n | (n+1));
    return n;
}

int main()
{
    int n = 0b1101;
    int setBit = setTheRightmostUnsetBit(n);
    cout<<bitset<32>(setBit)<<"\n";
    cout<<setBit;
    return 0;
}
