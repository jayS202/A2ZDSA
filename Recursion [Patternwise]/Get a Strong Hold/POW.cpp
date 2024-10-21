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
#include<bits/stdc++.h>
using namespace std;

double powRec(double x, long long nn){
    if(nn == 0){
        return 1;
    }

    if(nn%2==1){
        return x*powRec(x, nn-1);
    }else{
        return powRec(x*x, nn/2);
    }
}

double myPow(double x, int n) {
    long long nn = n;
    if(n<0) nn = -1 * nn;
    
    double res =  powRec(x,nn);
    
    if(n<0){
        res = (double)1.0/(double)res;
    } 
    return res;
}

int main()
{
    double x = 2.0000;
    int n = -2;
    cout<<myPow(x,n)<<"\n";
    return 0;
}
