// Same approach to Allocate Minimum number of pages and Split Array Largest Sum

// Painter's Partition Problem

// Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

//LeetCode solution
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
