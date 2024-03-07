// 4 Sum | Find Quads that add up to a target value
// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Brute
// TC - O(N^4), SC -  O(2 * no. of the quadruplets) 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target){
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;k<n;k++){
                    int sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// Better
// TC - O(N3*log(M)), SC - O(2 * no. of the quadruplets) 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target){
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int sum = nums[i]+nums[j];
                sum += nums[k];
                int fourth = target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// Optimal
// TC - O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array., SC - O(no. of quadruplets)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i!=0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j!=(i+1) && nums[j]==nums[j-1])continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = nums[i];
                sum+=nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
                else if(sum < target)k++;
                else l--;
            }
        }
    }
    return ans;
}



int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
