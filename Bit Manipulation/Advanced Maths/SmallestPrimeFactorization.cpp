

// Using Prime factors with TC of sqrt(n).
// TC - O(Q) * O(sqrt(N)), where Q - queries and N - number 
#include<bits/stdc++.h>
using namespace std;

vector<int> prime(int n){
    vector<int> ls;
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            ls.push_back(i);
            n = n/i;
        }
    }
    if(n!=1)ls.push_back(n);
    return ls;
}

vector<vector<int>>SPF(vector<int> &queries){
    vector<vector<int>> res;
    for(auto it: queries){
        res.push_back(prime(it));
    }
    
    return res;
}

int main()
{
    vector<int> queries = {15, 30, 10};
    vector<vector<int>> result = SPF(queries);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// Using seive to find the prime factors
// TC - O(N log(log N)) + (Q * log2 N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void seiveofErosthethes(vector<int> &arr){
    int n = 100000;
    arr.resize(n+1, 0);
    
    for(int i=2;i<=n;i++){
        arr[i] = i;
    }
    
    for(int i=2;i*i<=n;i++){
        if(arr[i]==i){
            for(int j=i*i;j<=n;j+=i){
                arr[j] = i;
            }
        }
    }
}

int main(){
    vector<int> queries = {15, 30, 10};
    vector<int> arr;
    vector<vector<int>> result;
    seiveofErosthethes(arr);
    
    for(auto it: queries){
        vector<int> ls;
        int n = it;
        while(n!=1){
            ls.push_back(arr[n]);
            n = n/arr[n];
        }
        result.push_back(ls);
    }
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
