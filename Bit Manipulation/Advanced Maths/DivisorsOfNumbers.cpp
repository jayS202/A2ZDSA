// Problem Statement - Print all divisors of a number


// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> printAllDivisors(int n){
    vector<int> ls;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            ls.push_back(i);
        }
    }
    return ls;
}

int main()
{
    int n;
    cin>>n;
    vector<int> res = printAllDivisors(n);
    for(auto it: res){
        cout<<it<<" "; 
    }
    return 0;
}


// TC - O(sqrt(N)), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> printAllDivisors(int n){
    vector<int> ls;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ls.push_back(i);
            if(n/i!=i)ls.push_back(n/i);
        }
    }
    return ls;
}

int main()
{
    int n;
    cin>>n;
    vector<int> res = printAllDivisors(n);
    for(auto it: res){
        cout<<it<<" "; 
    }
    return 0;
}
