// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

//Brute Force: Using Set
//Time Complexity: N log N
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int *arr, int n){
      set<int> s;
    
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    int k = s.size();
    int j = 0;
    for(int x: s){
        arr[j++]=x;
    }
    return k;
}

int main(){
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

//Optimal: using a for loop to array
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int *arr, int n){
      int i = 0;
      for(int j=0;j<n;j++){
            if(arr[j]!=arr[i]){
                i++;
                arr[i] = arr[j];
            }
      }
       return i+1;
}

int main(){
    int arr[] = {1,1,2,2,2,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
