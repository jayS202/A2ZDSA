// Set Ith Bit
// TC - O(!), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void SetithBit(int n, int i){
    int setBit = (n | (1<<i));
    cout<<bitset<32>(setBit)<<"\n";
    cout<<setBit;
}

int main()
{
    int n = 0b1101;
    int i = 1;
    SetithBit(n, i);
    return 0;
}
