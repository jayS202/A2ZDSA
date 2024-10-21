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

// Recursive solution
// TC - O(N), SC - O(1)
#include <bits/stdc++.h>
using namespace std;

double POWER(int x, long long n){
    if(n==0){
        return 1;
    }
    
    if(n%2==1){
        return x * POWER(x, n-1);
    }else{
        return POWER(x*x, n/2);
    }
}

double POW(int x, int n){
    long long nn = n;
    
    if(nn<0) nn = -1 * n;
    
    double res = POWER(x,nn);
    
    if(n<0) res = 1.0/res;
    return res;
}

int main()
{
    int x = 2;
    int n = 21;
    cout<<POW(x,n)<<endl;
    return 0;
}
