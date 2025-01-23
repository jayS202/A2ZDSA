// Problem Statement: Given a number n, the task is to find all prime factors of n.

// TC - O(N), SC - O(log N)
#include<bits/stdc++.h>
using namespace std;

vector<int> printPrimeFactors(int n){
    vector<int> ls;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            ls.push_back(i);
            while(n%i==0){
                n = n/i;
            }
        }
    }
    return ls;
}

int main(){
    int n;
    cin>>n;
    vector<int> res = printPrimeFactors(n);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}

// TC - O(root N * log N), SC - O(log N)
#include<bits/stdc++.h>
using namespace std;

vector<int> printPrimeFactors(int n){
    vector<int> ls;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ls.push_back(i);
            while(n%i==0){
                n = n/i;
            }
        }
    }
    if(n != 1)ls.push_back(n);
    return ls;
}

int main(){
    int n;
    cin>>n;
    vector<int> res = printPrimeFactors(n);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
