// Leaders in an Array
// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

// Brute
//TC - O(N^2) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int *arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader = false;
            }        
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};
    vector<int> ans = printLeadersBruteForce(arr,n);
    for(int i = 0;i<ans.size();i++){
          cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// Optimal
// TC - O(N) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int *arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i],maxi);
    }    
    return ans;
}

int main(){
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};
    vector<int> ans = printLeaders(arr,n);  
    for(int i = ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
