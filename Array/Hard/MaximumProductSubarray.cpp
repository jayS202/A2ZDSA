// Maximum Product Subarray in an Array
// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

// Brute
// TC - O(N^3), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> nums){
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int prod = 1;
            for(int k=i;k<=j;k++){
                prod = prod * nums[k];
                maxi = max(maxi, prod);
            }
        }
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// Better
// TC - O(N^2),SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> nums){
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int prod = 1;
        for(int j=i+1;j<n;j++){
                prod = prod * nums[j];
                maxi = max(maxi, prod);
            }
        }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// Optimal (Observation)
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        
        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];
        
        maxi = max(maxi, max(prefix,suffix));
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
