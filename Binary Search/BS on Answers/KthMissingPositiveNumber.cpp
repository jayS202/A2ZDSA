// Kth Missing Positive Number
// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.


// Brute
// TC - O(N), SC - O(1)
#include<bits/stdc++.h> 
using namespace std;

int missingK(vector<int> vec, int n, int k){
    for(int i=0;i<n;i++){
        if(vec[i]<=k){
            k++;
        }else{
            break;
        }
    }
    return k;
}

int main(){
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}


// Optimal
// TC - O(logN), N = size of the given array, SC - O(1)
#include<bits/stdc++.h> 
using namespace std;

int missingK(vector<int> vec, int n, int k){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        int missing = vec[mid]-(mid+1);
        if(missing<k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low + k;// (OR) high + 1 + k;
}

int main(){
    vector<int> vec = {2,3,4,7,11};
    int n = vec.size(), k = 5;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
