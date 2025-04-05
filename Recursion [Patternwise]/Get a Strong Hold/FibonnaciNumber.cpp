#include<bits/stdc++.h>
using namespace std;

// TC - O(N)+O(N), SC - O(N)
int main()
{
    int n = 1;
    if(n==0){
        cout<<0;
    }else if(n == 1){
        cout<<0<<" "<<1;
    }else{
        int fib[n+1];
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2;i<=n;i++){
            fib[i] = fib[i-1]+fib[i-2];
        }
        for(int i=0;i<=n;i++){
            cout<<fib[i]<<" ";
        }
    }
    return 0;
}

// TC - O(2^N), SC - O(N)
int fib(int n){
    if(n<=1)return n;
    
    return fib(n-1)+fib(n-2);
}

int main(){
    int n = 6;
    res = fib(n);
    cout<<res;
    return 0;
}
