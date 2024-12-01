// Toggle ith bit

// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void ToggleithBit(int n, int i){
    int toggleBit = (n ^ (1<<i));
    cout<<bitset<32>(toggleBit)<<"\n";
    cout<<toggleBit;
}

int main()
{
    int n = 0b1101;
    int i = 2;
    ToggleithBit(n, i);
    return 0;
}
