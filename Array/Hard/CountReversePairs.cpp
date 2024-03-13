// Count Reverse Pairs
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Brute
// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int team(vector<int> a, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>2*a[j]){
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}


// Optimal
// TC - O(2N*logN), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

int reversePair(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int cnt = 0; 
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right])right++;
        cnt = cnt + (right - (mid+1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low>=high)return cnt;
    int mid = (low+high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=reversePair(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int team(vector<int> &arr, int n){
    return mergeSort(arr, 0, n-1);
}

int main(){
    vector<int> arr = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(arr, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
