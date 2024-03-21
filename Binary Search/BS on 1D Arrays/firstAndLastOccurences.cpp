// First and Last Occurrences in Array
// Problem Statement: Given a sorted array arr of n integers and a target value k. Write a program to find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

// Using linear search
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

pair<int,int> firstAndLastPosition(vector<int> arr, int n, int k){
    int first=-1, last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            if(first == -1)first = i;
            last = i;
        }
    }
    return {first,last};
}

int main(){
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 12;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}


// Using Lower Bound and Upper Bound
// TC - O(log n), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> arr, int n, int k){
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int upper_bound(vector<int> arr, int n, int k){
    int low = 0, high = n-1;
    int ans=n;
    while(low<high){
        int mid = (low + high)/2;
        if(arr[mid]>k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int,int> firstAndLastPosition(vector<int> arr, int n, int k){
    int lb = lower_bound(arr,n,k);
    if(arr[lb]!=k || lb == n)return {-1,-1};
    int ub = upper_bound(arr, n, k);
    return {lb, ub-1};
}

int main(){
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 10;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}

// Using Binary Search
// TC - O(log n), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int firstbinarysearch(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==k){
            ans = mid;
            high = mid - 1;
        }else if(arr[mid]<k){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return ans;
}

int lastbinarysearch(vector<int> &arr, int n, int k){
    int low=0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==k){
            ans = mid;
            low = mid + 1;
        }else if(arr[mid]>k){
            high = mid - 1; 
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

pair<int,int> firstAndLastPosition(vector<int> arr, int n, int k){
    int first = firstbinarysearch(arr, n, k);
    if(first==-1)return {-1,-1};
    int last = lastbinarysearch(arr,n,k);
    return {first,last};
}

int main(){
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}
