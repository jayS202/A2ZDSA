//Problem Statement: Given an array, we have to find the largest element in the array.

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
