//Count Maximum Consecutive One’s in the array
//Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> nums){
  int cnt = 0;
  int maxi = 0;
  for(int i=0;i<nums.size();i++){
    if(nums[i]==1){
      cnt++;
    }else{
      cnt = 0;
    }

    maxi = max(maxi,cnt);
  }
  return maxi;
}

int main(){
  vector < int > nums = { 1, 1, 0, 1, 1, 1 ,0, 1, 1};
  int ans = findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}
