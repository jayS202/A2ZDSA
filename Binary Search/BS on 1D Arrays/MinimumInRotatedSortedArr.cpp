// Minimum in Rotated Sorted Array
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

// TC - O(log N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }else{
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}

// When arr[low]<=arr[high]
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            mini = min(mini, arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }else{
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
