// Generates all subsequences (i.e., all combinations of elements preserving order but not necessarily contiguous).
// TC - O(2^N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &ds){
    if(ds.size()==0){
        cout<<"{}"<<" ";
    }else{
        for(auto it: ds){
            cout<<it<<" ";
        }
    }
    cout<<"\n";
}

void printALLSub(int *arr, int ind, vector<int> &ds, int n){
    if(ind>=n){
        print(ds);
        return;
    }
    
    // Take
    ds.push_back(arr[ind]);
    printALLSub(arr, ind+1, ds, n);
    
    // Not take
    ds.pop_back();
    printALLSub(arr, ind+1, ds, n);
}

void subseq(int *arr, int n){
    vector<int> ds;
    printALLSub(arr, 0, ds, n);
}

int main(){
    int arr[] = {3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    subseq(arr, n);
    return 0;
}
