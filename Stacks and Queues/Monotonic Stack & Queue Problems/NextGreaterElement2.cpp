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


// Optimal Solution
// You traverse the array twice in reverse (to simulate the circular property).
// The stack keeps track of “potential next greater” elements.
// For each element:
// - Pop smaller/equal values (they can't be next greater).
// - The top of the stack is the next greater element.
// - Then push the current element.

// TC - O(N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterEle(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);
    
    for(int i=2*n-1;i>=0;i--){
        
        int ind = i%n;
        int curele = arr[ind];
        
        while(!st.empty() && st.top()<=curele){
            st.pop();
        }
        
        if(i<n){
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
        }
        
        st.push(curele);
    }
    return ans;
}

int main(){
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    vector<int> res = NextGreaterEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// OPTIMAL - Similar to Next Greater Element
#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterEle(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    for(int i=2*n-1;i>=0;i--){
        int idx = i%n;
        while(!st.empty() && st.top()<=arr[idx]) st.pop();
        if(!st.empty() && i<=n) res[idx] = st.top();  
        st.push(arr[idx]);
    }
    return res;
}

int main(){
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> res = NextGreaterEle(arr);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
