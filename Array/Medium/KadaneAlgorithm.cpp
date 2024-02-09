// Kadane’s Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

//Brute - Slightly Better
// TC - O(N3), where N = size of the array.
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

//Optimal
// O(N), where N = size of the array.
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum>maxi){
            maxi=sum;
        }

        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

//Optimal Follow Up
// O(N), where N = size of the array.
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    int arrStart = -1, arrEnd = -1;
    int start = 0;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
            arrStart = start;
            arrEnd = i;
        }

        if(sum<0){
            sum = 0;
        }
    }
    cout<<"The subarray is [ ";
    for(int i=arrStart;i<=arrEnd;i++){
            cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return maxi;
}

int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
