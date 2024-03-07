// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Brute
// TC - O(N^3) , SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int Xor = 0;
            for(int k=i;k<=j;k++){
                Xor = Xor ^ a[k];
                if(Xor == k)cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// Better
// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int Xor = 0;
        for(int j=i;j<n;j++){
                Xor = Xor ^ a[j];
                if(Xor == k)cnt++;
            }
        }
    return cnt;
}

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// Optimal
// TC - O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array., SC - O(N)
#include<bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
