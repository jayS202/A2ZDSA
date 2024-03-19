// Implement Lower Bound
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

//Lower Bound
// TC - O(1), SC - O(logN)
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 18;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
