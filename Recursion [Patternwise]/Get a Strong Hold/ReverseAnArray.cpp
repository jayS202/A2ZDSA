#include<bits/stdc++.h>
using namespace std;

// TC - O(N) SC - O(N)
vector<int> reverseAnArr(vector<int> &arr){
    vector<int> ans;
    for(int i=arr.size()-1;i>=0;i--){
        ans.push_back(arr[i]);
    }
    return ans;
}

// TC - O(N/2) SC - O(1)
vector<int> reverseAnArr(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end/2){
        swap(arr[start],arr[end-start]);
        start++;
    }
    return arr; 
}

// Recursion
// TC - O(N/2) SC - O(N)
void reverseAnArr(vector<int> &arr, int start, int n){
    if(start>=n/2){
        return;
    }
    
    swap(arr[start], arr[n-1-start]);
    
    reverseAnArr(arr, start+1, n); 
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    reverseAnArr(arr, 0, n);
    // vector<int> res = reverseAnArr(arr, 0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
