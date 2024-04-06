// Find the Smallest Divisor Given a Threshold
// Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

// Brute
// TC - O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array., SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &arr, int limit){
    int mini= INT_MAX, maxi = INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    for(int i=mini;i<=maxi;i++){
        int d = 0;
        int n = arr.size();
        for(int j=0;j<n;j++){
            d += ceil((double)arr[j]/(double)i);
        }
        if(d<=limit)
            return i;
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}

// Optimal
// TC - O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array., SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int sumDiv(vector<int> &arr, int mid){
    int d = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        d += ceil((double)arr[i]/(double)mid);
    }
    return d;
}

int smallestDivisor(vector<int> &arr, int limit){
    int mini= INT_MAX, maxi = INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    int low = mini, high = maxi;
    while(low<=high){
        int mid = (low+high)/2;
        int num = sumDiv(arr, mid);
        if(num<=limit){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
