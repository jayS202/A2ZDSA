//Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

//Brute force
#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> arr){
  vector<int> temp;
  for(int i=0;i<n;i++){
    if(arr[i]!=0){
      temp.push_back(arr[i]);
    }
  }

  int s = temp.size();
  for(int i=0;i<s;i++){
    arr[i]=temp[i];
  }
  for(int i=s;i<n;i++){
    arr[i]=0;
  }
  return arr;
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}


//Optimal: In-place
#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> arr){
  int k=0;
  for(int i=0;i<n;i++){
    if(arr[i]!=0){
      arr[k++]=arr[i];
    }
  }
  for(int i=k;i<n;i++){
    arr[i]=0;
  }
  return arr;
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
