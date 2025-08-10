#include<bits/stdc++.h>
using namespace std;

// Version 1:
// TC - O(N), SC - O(1)
vector<int> zigzag(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        if((i%2==0 && arr[i]>arr[i+1])){
            swap(arr[i],arr[i+1]);
        }
        else if(i%2!=0 && arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}

// Similar to Version - Removed the Duplicate Code
vector<int> zigzag(vector<int> &arr, int n){
    for(int i=0;i<n-1;i++){
        if((i%2==0 && arr[i]>arr[i+1]) || (i%2!=0 && arr[i]<arr[i+1])){
            swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}


// Version - 3 (Slightly more wfficent as it is not using %)
vector<int> zigzag(vector<int> &arr, int n){
    bool expectLess = true;
    for(int i=0;i<n-1;i++){
        if(expectLess){
            if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
        }else{
            if(arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
        }
        expectLess = !expectLess;
    }
    return arr;
}

int main()
{
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};
    int n = arr.size();
    vector<int> res = zigzag(arr, n);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
