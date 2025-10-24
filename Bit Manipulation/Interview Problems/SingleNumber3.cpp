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

void TwoNumAppearingOddNum(vector<int> &arr){
    int n = arr.size();
    int num = 0;
    
    // Step 1: Xor All elements of the array
    for(int i=0;i<n;i++){
        num ^= arr[i];
    }
    
    // Step 2: Find the rightmost set bit
    int res = (num & (num-1)) ^ num;
    
    // Step 3: Compare the distict bit with each elements
    // Concept of Buckets: On comparing,
    // if result is 0: push it to B1
    // if result is 1: push it to B2
    int B1 = 0; int B2 = 0;
    
    for(int i=0;i<n;i++){
        if((arr[i]&res)){
            B1 ^= arr[i]; 
        }else{
            B2 ^= arr[i];
        }
    }
    
    cout<<"Num 1: "<<B1<<'\n';
    cout<<"Num 2: "<<B2<<'\n';
}

int main(){
    vector<int> arr = {2, 4, 7, 9, 2, 4};
    TwoNumAppearingOddNum(arr);
    return 0;
}
