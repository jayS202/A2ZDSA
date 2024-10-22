// Optimal
// TC - O(log N), SC - O(1)
#include <bits/stdc++.h>
using namespace std;

// long long POW(long long base, long long expo, long long mod){
//     long long ans = 1;
//     while(expo>0){
//         if(expo%2==1){
//             ans = (ans * base)%mod;
//             expo = expo - 1;
//         }else{
//             base = (base * base)%mod;
//             expo = expo/2;
//         }
//     }
//     return ans;
// }

long long modExpo(long long base, long long expo, long long mod){
    long long ans = 1;
    while(expo>0){
        if(expo%2==1){
            ans = (ans * base)%mod;
        }
        base = (base * base)%mod;
        expo = expo/2;
    }
    return ans;
}

long long goodNum(long long n){
    long long MOD = 1e9+7;
    long long evenpositions = (n+1)/2;
    long long oddpositions = n/2;
    
    long long evenpart = modExpo(5, evenpositions, MOD);
    long long oddpart = modExpo(4, oddpositions, MOD);
    
    long long result = (evenpart * oddpart)%MOD;
    return result;
}

int main()
{
    long long n = 50;
    cout<<goodNum(n)<<"\n";
    return 0;
}
