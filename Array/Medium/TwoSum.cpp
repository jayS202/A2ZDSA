// Problem Statement: Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

//Brrute 
// TC - O(n^2)
#include<bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> arr, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}

// Better 
// TC - O(n * lon n)

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    map<int, int> mapi;
    for(int i=0;i<n;i++){
        int rem = target - nums[i];
        if(mapi.find(rem)!=mapi.end()){
            return {mapi[rem],i};
        }
        mapi[nums[i]]=i;
    }
    return {-1,-1};
}

int main(){
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans[0] <<" "<< ans[1]<< endl;
    return 0;
}

string twoSum(int n, vector<int>& arr, int target)
{
    map<int,int> Mapi;
    for(int i=0;i<n;i++){
        int rem = target - arr[i];
        if(Mapi.find(rem)!=Mapi.end()){
            return "YES";
        }
        Mapi[arr[i]] = i;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}

// optimal
//
