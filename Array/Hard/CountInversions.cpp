// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

// Brute
// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int numberOfInversions(vector<int> a, int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}


// Optimal
// TC - O(N*log N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> arr, int low, int mid, int high){
    int cnt = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
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
    
    for(int i=low;i<high;i++){
        arr[i] = temp[i-low];
    }
    
    return cnt;
}

int mergeSort(vector<int> arr, int low, int high){
    int cnt = 0;
    if(low>=high)return cnt;
    int mid = (low+high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=merge(arr, low, mid, high);
    return cnt;
}

int numberOfInversions(vector<int> arr, int n){
    return mergeSort(arr, 0, n-1);
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(arr, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}
