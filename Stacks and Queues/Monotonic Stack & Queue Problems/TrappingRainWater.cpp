// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// TC - O(3N), SC - O(2N)
#include<bits/stdc++.h>
using namespace std;

int TrappingRainWater(vector<int> &arr){
    int n = arr.size();
    int ans = 0;
    vector<int> left(n);
    vector<int> right(n);
    left[0] = arr[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1], arr[i]);
    }
    
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1], arr[i]);
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]<left[i] && arr[i]<right[i]){
            ans += (min(left[i], right[i])-arr[i]); 
        }
    }
    return ans;
}

int main(){
    vector<int> height = {4,2,0,3,2,5};
    int res = TrappingRainWater(height);
    cout<<res<<" ";
    return 0;
}
