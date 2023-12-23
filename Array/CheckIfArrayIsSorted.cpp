
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
