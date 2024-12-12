// Problem Statement: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Brute Force
// TC - O(N), SC - O(N) where N is the size of the array.
#include<bits/stdc++.h>
using namespace std;

int SingleNumber(vector<int> &nums){
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    
    for(auto it: mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 3, 2, 3, 2};
    cout<<SingleNumber(nums);
    return 0;
}

// Optimal Approach
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int SingleNumber(vector<int> &nums){
    int Xor = nums[0];
    for(int i=1;i<nums.size();i++){
        Xor = Xor ^ nums[i]; 
    }
    return Xor;
}

int main()
{
    vector<int> nums = {4, 3, 2, 3, 2};
    cout<<SingleNumber(nums);
    return 0;
}
