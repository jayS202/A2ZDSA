// Binary Search
// Problem statement: You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.

// Iterative approach
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int target){
    int n = a.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==target) return mid;
        else if(a[mid]>target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 120;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< ind << endl;
    return 0;
}

// Recursive approach
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> a, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low + high)/2;
    if(a[mid]==target) return mid;
    else if(a[mid]>target){
        return binary_search(a, low, mid-1, target);
    }else{
        return binary_search(a, mid+1, high, target);
    }
}

int binarySearch(vector<int> a, int target){
    int n = a.size();
    return binary_search(a, 0, n-1, target);
}

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 12;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "<< ind << endl;
    return 0;
}
