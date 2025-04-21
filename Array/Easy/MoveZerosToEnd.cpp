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

// Better
// TC - O(N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> &arr){
    int i=0;
    int j=n-1;
    vector<int> ans(n);
    for(int k=0;k<n;k++){
        if(arr[k]==0){
            ans[j] = arr[k];
            j--;
        }else{
            ans[i] = arr[k];
            i++;
        }
    }
    return ans;
}

int main()
{
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
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> &arr){
    int j = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j = i;
            break;
        }
    }
    
    if(j==-1)return arr;
    
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
