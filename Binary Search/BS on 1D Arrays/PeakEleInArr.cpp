// Peak element in Array
// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

// Brute
// TC - O(N),SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if((i==0||arr[i]>arr[i-1])&&(i==n-1||arr[i]>arr[i+1])){
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

// Optimal
// TC - O(log N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> arr){
    int n = arr.size();
    if(n==1)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    int low = 1, high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if((arr[mid]>arr[mid-1])&&(arr[mid]>arr[mid+1]))return mid;
        if(arr[mid]>arr[mid-1]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
