// Problem Statement: Given a circular integer array arr, return the next greater element for every element in arr.
// The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.
// If it doesn't exist, return -1 for that element element.


// Brute Force
// - Imagine a virtual array extending the original array.
// - We traverse until the n element of the array.
// - If the index exceeds the n element we the virtual array
//         k = j%n
// - The moment we find the number greater than the current element in the i. We break the loop and continue furthur.

// TC - O(N^2), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterEle(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<i+n;j++){
            int k = j%n;
            if(arr[k]>arr[i]){
                ans[i] = arr[k];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> res = NextGreaterEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
