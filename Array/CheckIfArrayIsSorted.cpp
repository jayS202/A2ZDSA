
//Problem Statement: Check if the given array is sorted.

#include<bits/stdc++.h>
using namespace std;

bool checkArrSorted(vector<int> arr, int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr;
    arr = {1,3,6,7,8};
    int n = arr.size();
    (checkArrSorted(arr, n)==true)?cout<<"Array is sorted":cout<<"Array is not sorted";
    return 0;
}

//LeetCode
// 1752. Check if Array Is Sorted and Rotated.
#include<bits/stdc++.h>
using namespace std;

bool checkArrSorted(vector<int> arr, int n){
    int cnt = 0;
    //Ex - [1,2,4,6,8]
    //In this case the ascending order does not breaks inside the array. So cnt=0 , But when we check the last element and the first element, cnt becomes 1
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            cnt++;
        }
    }
    //Ex- [5,6,9,1,2]
    //In this case the ascending order breaks inside the array, So cnt becomes 1. But nums[n-1]<nums[0] So cnt doesn't increases. So cnt=1
    if(arr[n-1]>arr[0]){
        cnt++;
    }
    if(cnt<=1){return true;}else{return false;}
}

int main(){
    vector<int> arr;
    arr = {1,2,3};
    int n = arr.size();
    (checkArrSorted(arr, n)==true)?cout<<"Array is sorted":cout<<"Array is not sorted";
    return 0;
}
