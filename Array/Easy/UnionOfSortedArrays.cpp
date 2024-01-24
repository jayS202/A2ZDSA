//Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.


//Brute Force
#include<bits/stdc++.h>
using namespace std;

vector<int> FindUnion(vector<int> arr1,vector<int> arr2,int n, int m){
  set<int> s;
  vector<int> temp;
  for(int i=0;i<m;i++){
    s.insert(arr1[i]);
  }
  for(int j=0;j<n;j++){
    s.insert(arr2[j]);
  }
  for(auto &x: s){
    temp.push_back(x);
  }
  return temp;
}

int main(){
  int m = 6, n = 10;
  vector<int> arr1 = {2,2,2,3,3,4};
  vector<int> arr2 = {1,2,4,4,6,6,6,7,8,10}; 
  vector <int> Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}



// Optimal solution
#include<bits/stdc++.h>
using namespace std;

vector<int> FindUnion(vector<int> arr1,vector<int> arr2,int n, int m){
    vector<int> temp;
    int i = 0;
    int j = 0;
    while(i<m && j<n){
      if(arr1[i]<=arr2[j]){
        if(temp.size()==0 || temp.back() != arr1[i]){ 
            temp.push_back(arr1[i]);
        }
        i++;
      }else{
        if(temp.size()==0 || temp.back()!= arr2[j]){
          temp.push_back(arr2[j]);
        }
        j++;
      }
    }
    while (i<m)
    {
        if(temp.back() != arr1[i]){ 
            temp.push_back(arr1[i]);
        }
        i++;
    }

    while(j<n){
        if(temp.back()!= arr2[j]){
          temp.push_back(arr2[j]);
        }
        j++;
    }
    return temp;
}

int main(){
  int m = 6, n = 10;
  vector<int> arr1 = {2,2,2,3,3,4};
  vector<int> arr2 = {1,2,4,4,6,6,6,7,8,10}; 
  vector <int> Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}



