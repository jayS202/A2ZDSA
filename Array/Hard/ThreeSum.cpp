// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Brute
// TC - O(N3 * log(no. of unique triplets)), where N = size of the array. SC -  O(2 * no. of the unique triplets)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> arr){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);    
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Better 
// TC - O(N2 * log(no. of unique triplets)), where N = size of the array, SC - O(2 * no. of the unique triplets) + O(N)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> arr){
    
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// Optimal
// TC - O(NlogN)+O(N2), where N = size of the array, SC - O(no. of quadruplets)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> arr){
    set<vector<int>> st;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                st.insert(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k-1])k--;
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
}
