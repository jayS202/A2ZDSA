// next_permutation : find next lexicographically greater permutation
// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

//Optimal
//Time Complexity: O(3N), where N = size of the given array
//Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> arr){
    int n = arr.size();
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
             ind = i;
             break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    
    for(int i=n-1;i>ind;i--){
        if(arr[i]>ind){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
    return arr;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(arr);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}
