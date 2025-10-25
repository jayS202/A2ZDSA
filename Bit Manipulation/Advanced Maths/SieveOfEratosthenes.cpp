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

// For given multiple ranges
#include<bits/stdc++.h>
using namespace std;

void sieveOfErothstatus(vector<pair<int,int>> &arr){
    for(auto it: arr){
        int query = max(it.first, it.second);
        vector<int> ans(query+1, 1);
        vector<int> ls;
        
        ans[0] = ans[1] = 0;
        for(int i=2;i*i<=query;i++){
            if(ans[i]==1){
                for(int j=i*i;j<=query;j+=i){
                    if(ans[j]!=0) ans[j] = 0;
                }
            }
        }
        
        for(int k=it.first;k<=it.second;k++){
            if(ans[k] == 1) ls.push_back(k);
        }
        
        for(auto it: ls){
            cout<<it<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    vector<pair<int,int>> arr = {{2,4},{4,7}};
    sieveOfErothstatus(arr);
    return 0;
}
    
