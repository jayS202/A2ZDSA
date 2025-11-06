// Problem Statement: Given an integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// TC - O(N^2), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterEle(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,3,2,4};
    vector<int> res = NextGreaterEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
