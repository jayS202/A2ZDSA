//Problem Statement: Given an array, we have to find the largest element in the array.

// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int largestele(vector<int> arr, int n){
    int max = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[max]){
            max = i;
        }
    }
    return arr[max];
}

int main(){
    vector<int> arr;
    arr = {3,4,6,8,4,12,5,9};
    int n = arr.size();
    cout<<largestele(arr, n)<<endl;
    return 0;
}

// Optimal 
// TC- O(N) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void largestElement(vector<int> &arr){
    int maxi = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    cout<<maxi;
}

int main(){
    vector<int> arr = {8,10,5,7,9};
    int n = arr.size();
    cout<<largestElement(arr, 0, 0, n);
    return 0;
}

// Using Recursion 
#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int i, int maxi, int n){
    if(i>=n)return maxi;
    
    if(arr[i]>maxi){
        maxi = arr[i];
    }
    
    return largestElement(arr, i+1, maxi, n);
}

int main(){
    vector<int> arr = {8,10,5,7,9};
    int n = arr.size();
    cout<<largestElement(arr, 0, 0, n);
    return 0;
}
