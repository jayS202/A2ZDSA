// Fast exponential
// TC - O(log N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

double fastexpo(double b, int expo){
    double base = b;
    double ans = 1.0;
    long long expi = expo;
    if(expi<0) -1 * expi;
    while(expi>0){
        if(expi%2){
            expi--;
            ans = ans * base;
        }else{
            expi /= 2;
            base = base * base;
        }
    }
    if(expi<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}

int main(){
    double b = 2;
    int expo = 10;
    double ans = fastexpo(b,expo);
    cout<<ans<<endl;
    return 0;
}
