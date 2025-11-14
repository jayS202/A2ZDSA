// Problem Statement: Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
// If there is no smaller element to the right, then the NSE is -1.

// Brute Force
// TC - O(N^2), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallerEle(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4,8,5,2,25};
    vector<int> res = NextSmallerEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}

// Optimal Solution
// TC - O(N), SC - O(N)
vector<int> NextSmallerEle(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        
        if(!st.empty()){
            ans[i] = st.top();
        }else{
            ans[i] = -1;
        }
        
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {10, 9, 8, 7};
    vector<int> res = NextSmallerEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
