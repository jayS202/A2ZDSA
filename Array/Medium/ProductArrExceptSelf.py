# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

# You must write an algorithm that runs in O(n) time and without using the division operation.

# TC - O(3N), SC - O(2N)
arr = [1,2,3,4]
n = len(arr)

#  Prefix
prefix = [0]*n
prefix[0] = 1
for i in range(1,n):
    prefix[i] = prefix[i-1] * arr[i-1]
    
#  Suffix
suffix = [0]*n
suffix[n-1] = 1
for i in range(n-2,-1,-1):
    suffix[i] = suffix[i+1]*arr[i+1]

# answrr
ans = [0]*n
for i in range(n):
    ans[i] = prefix[i]*suffix[i]
    
print(ans)
