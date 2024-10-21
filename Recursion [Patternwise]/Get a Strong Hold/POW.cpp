// Optimal Approch
// TC - O(log2 N), SC - O(1)
#include <bits/stdc++.h>
using namespace std;

double POW(double x, int n){
    long long nn = n;
    double ans = 1;
    if(nn<0) nn = -1 * nn;
    while(nn>0){
        if(nn%2==1){
            ans = ans * x;
            nn = nn-1;
        }else{
            x = x * x;
            nn = nn/2;
        }
    }
    if(n<0) ans = (double)1.0/(double)ans;
    return ans;
}

int main()
{
    int x = 2;
    int n = 21;
    cout<<POW(x,n)<<"\n";
    return 0;
}
