// Find the number that appears once, and the other numbers twice
// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include<bits/stdc++.h>
using namespace std;

// Brute Force: Naive Approach
// Time Complexity: O(N2), where N = size of the given array.
// Space Complexity: O(1) as we are not using any extra space.
int getSingleElement(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int cnt = 0;
        int num = arr[i];
      for(int j=0;j<n;j++){
        if(arr[j]==num){
          cnt++;
        }
      }
      if(cnt == 1){
        return arr[i];
      }
    }
}
int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}


//Better 1: Hashing
// Time Complexity: O(N)+O(N)+O(N), where N = size of the array
// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
int getSingleElement(vector<int> arr){
  int n = arr.size();
  int maxi = arr[0];
  for(int i=0;i<n;i++){
    maxi = max(maxi,arr[i]);
  }
  int hash[maxi+1] = {0};
  for(int i=0;i<n;i++){
    hash[arr[i]]++;
  }
  for(int i=0;i<n;i++){
    if(hash[arr[i]]==1){
      return arr[i];
    }
  }
}
int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

//Better 2: Map
//Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int getSingleElement(vector<int> arr){
    int n = arr.size();
    map<int,int> Mpp;

    for(int i=0;i<n;i++){
      Mpp[arr[i]]++;
    }

    for(auto it: Mpp){
      if(it.second == 1){
        return it.first;
      }
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}


//Optimal: XOR
// Time Complexity: O(N), where N = size of the array.
// Reason: We are iterating the array only once.
// Space Complexity: O(1) as we are not using any extra space.
int getSingleElement(vector<int> arr){
  int XOR = 0;
  int n = arr.size();
  for(int i=0;i<n;i++){
    XOR = XOR ^ arr[i];
  }
  return XOR;
}
int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
