//Problem Statement: Find the Intersection of two Arrays

//Brute Force
#include<bits/stdc++.h>
using namespace std;

 vector<int> Intersection(vector<int> arr1,vector<int> arr2,int n, int m){
        vector<int> ans;
        int vis[n] = {0};
        for(int i=0;i<m;i++){
          for(int j=0;i<n;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                  ans.push_back(arr1[i]);
                  vis[j]=1;
                  break;
            }
            if(arr2[j]>arr1[i])break;
          }
        }
        return ans;
 }

int main(){
  vector<int> arr1 = {1,2,2,3,3,4,5,6};
  vector<int> arr2 = {2,3,3,5,6,6,7}; 
  int m = arr1.size();
  int n = arr2.size();
  vector <int> Inter = Intersection(arr1, arr2, n, m);
  cout << "Intersection of arr1 and arr2 is  " << endl;
  for (auto & val: Inter)
    cout << val << " ";
  return 0;
}


//Optimal
#include<bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> arr1,vector<int> arr2,int n, int m){
      vector<int> ans;
      int i = 0;
      int j = 0;
      while(i<m && j<n){
        if(arr1[i]<arr2[j]){
          i++;
        }
        else if(arr2[j]<arr1[i]){
          j++;
        }
        else{
          ans.push_back(arr1[i]);
          i++;
          j++;
        }
      }
       return ans;
}

int main(){
  vector<int> arr1 = {1,2,2,3,3,4,5,6};
  vector<int> arr2 = {2,3,3,5,6,6,7}; 
  int m = arr1.size();
  int n = arr2.size();
  vector <int> Inter = Intersection(arr1, arr2, n, m);
  cout << "Intersection of arr1 and arr2 is  " << endl;
  for (auto & val: Inter)
    cout << val << " ";
  return 0;
}
