// Floor and Ceil in Sorted Array
// Problem Statement: You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

// TC - O(log n), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int getfloor(int *arr, int n, int x){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<=x){
            ans = arr[mid];
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int getceil(int *arr, int n, int x){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = arr[mid];
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

 

pair<int,int> getFloorAndCeil(int *arr, int n, int x){
    int f = getfloor(arr, n, x);
    int c = getceil(arr, n, x);
    return make_pair(f,c);
}

 
int main(){
    int arr[] = {3, 4, 4, 7, 8, 10};
              int n = 6, x = 5;
              pair<int, int> ans = getFloorAndCeil(arr, n, x);
              cout << "The floor and ceil are: " << ans.first
                   << " " << ans.second << endl;
              return 0;
}
