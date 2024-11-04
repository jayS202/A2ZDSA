// LEARN ALL THE PATTERNS OF SUBSEQUENCES

// TC - O(2^N), SC - O(N)

// 1 - Find the subsequence whose sum is equal to s.
#include<bits/stdc++.h>
using namespace std;

void implement(int ind, vector<int> &ds, int sum, int* arr, int k, int n){
    if(ind == n){
        if(sum == k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    
    // Take
    ds.push_back(arr[ind]);
    sum += arr[ind];
    implement(ind+1, ds, sum, arr, k, n);
    
    // Not Take
    ds.pop_back();
    sum -= arr[ind];
    implement(ind+1, ds, sum, arr, k, n);
}

void getAllSubSumK(int *arr, int k, int n){
    vector<int> ds;
    implement(0, ds, 0, arr, k, n);
}

int main()
{
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    getAllSubSumK(arr, k, n);
    return 0;
}

// 2 - Find only the first occurence of the subsequence whose sum is equal to s.
#include<bits/stdc++.h>
using namespace std;

bool implement(int ind, vector<int> &ds, int sum, int* arr, int k, int n){
    if(ind == n){
        if(sum == k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<"\n";
            return true;
        }
        return false;
    }
    
    // Take
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if(implement(ind+1, ds, sum, arr, k, n)==true) return true;
    
    // Not Take
    ds.pop_back();
    sum -= arr[ind];
    if(implement(ind+1, ds, sum, arr, k, n)==true) return true;
    
    return false;
}

void getAllSubSumK(int *arr, int k, int n){
    vector<int> ds;
    implement(0, ds, 0, arr, k, n);
}

int main()
{
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    getAllSubSumK(arr, k, n);
    return 0;
}

// Count the number of subsequence whose sum is equal to s
#include<bits/stdc++.h>
using namespace std;

int implement(int ind, int sum, int* arr, int k, int n){
    if(ind == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    
    // Take
    sum += arr[ind];
    int l = implement(ind+1, sum, arr, k, n);
    
    // Not Take
    sum -= arr[ind];
    int r = implement(ind+1, sum, arr, k, n);
    
    return l + r;
}

void getAllSubSumK(int *arr, int k, int n){
    cout<< implement(0, 0, arr, k, n);
}

int main()
{
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    getAllSubSumK(arr, k, n);
    return 0;
}
