// Similar the question Allocate minimum number of pages

// Split Array - Largest Sum

// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

class Solution {
private:
    int func(vector<int> &nums, int target, int n){
        int cnt = 1, arrSum = 0;
        for(int i=0;i<n;i++){
            if(arrSum + nums[i]<=target){
                arrSum += nums[i];
            }else{
                cnt++;
                arrSum = nums[i];
            }
        }
        return cnt;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            int num = func(nums, mid, n);
            if(num > k)low =  mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
