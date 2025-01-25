// Problem Statement: 

// TC - O(N) + O(N log(log N)) + O(N), SC - O(N) 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1, 1);
    
    for(int i=2;i*i<=n;i++){
        if(arr[i]!=0){
            for(int j=i*i;j<n;j+=i){
                arr[j] = 0;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(arr[i] == 1)cout<<i<<" ";
    }
    return 0;
}
