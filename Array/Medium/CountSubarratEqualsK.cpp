// Count Subarray sum Equals K
// Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

// Brute
// TC - O(N^3) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int K=i;K<=j;K++){
                 sum += arr[K];
            }
            if(sum == k)
                 cnt++;
        }
    }
    return cnt;
}

int main(){
    vector arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

// Better
// TC - O(N^2) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == k)
                 cnt++;
        }
    }
    return cnt;
}

int main(){
    vector arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

// Optimal
// TC - O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array. SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k){
   unordered_map<int,int> mpp;
   mpp[0]=1;
   int preSum = 0, cnt = 0;
   for(int i=0;i<arr.size();i++){
       preSum += arr[i];
       int remov = preSum - k;
       cnt += mpp[remov];
       mpp[preSum] += 1;
   }
   return cnt;
}

int main(){
    vector arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
