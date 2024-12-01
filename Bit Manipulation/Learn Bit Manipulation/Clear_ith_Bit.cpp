// Clear Ith Bit

// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void ClearithBit(int n, int i){
    int clearBit = (n & ~(1<<i));
    cout<<bitset<32>(clearBit)<<"\n";
    cout<<clearBit;
}

int main()
{
    int n = 0b1101;
    int i = 2;
    ClearithBit(n, i);
    return 0;
}
