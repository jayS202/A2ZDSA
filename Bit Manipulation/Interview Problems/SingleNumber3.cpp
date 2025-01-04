// Problem Statement - You are given an array 'arr' of size 'n'.
// It contains an even number of occurrences for all numbers except two numbers.
// Find those two numbers which have odd occurrences and return in decreasing order.

// Brute 
// TC - O(N log m) , SC - O(m)
#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber3(vector<int> &arr){
    unordered_map<int,int> mpp;
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    
    for(auto it: mpp){
        if(it.second == 1){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,4,2,14,3,7,7,3};
    vector<int> res = singleNumber3(arr);
    for(int it: res){
        cout<<it<<" ";
    }
    return 0;
}

// Optimal Solution
// TC - O(2N) , SC - O(1)
#include<bits/stdc++.h>
using namespace std;

pair<int,int> singleNumber3(vector<int> &arr){
    int n = arr.size();
    int num = 0, b1 = 0, b2 = 0;
    for(int i=0;i<n;i++){
        num = num ^ arr[i];
    }
    int rightmost = (num & (num-1))^num;
    for(int i=0;i<n;i++){
        if(arr[i]&rightmost){
            b1 = b1^arr[i];
        }else{
            b2 = b2^arr[i];
        }
    }
    return {b1,b2};
}

int main()
{
    vector<int> arr = {2,4,2,14,3,7,7,3};
    pair<int,int> res = singleNumber3(arr);
    cout<<res.first<<" "<<res.second<<"\n";
    return 0;
}
