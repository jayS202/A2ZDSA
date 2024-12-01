// Check if a number is power of 2 or not
// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void CheckIfNumIsPowOf2(int n){
    if(n & (n-1) != 0){
        cout<<n<<" is not a power of 2";    
    }else{
        cout<<n<<" is power of 2";    
    }

}

int main()
{
    int n = 32;
    CheckIfNumIsPowOf2(n);
    return 0;
}
