// Aggressive Cows : Detailed Solution
// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.


// Brute
// TC - O(N log N) *  O(N *(max(stalls[])-min(stalls[])), SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows>=cows)return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int limit = stalls[n-1]-stalls[0];
    for(int i=1;i<=limit;i++){
        if(canWePlace(stalls, i, cows)){
            continue;
        }else{
            return i-1;
        }
    }
    return limit;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

// Optimal
// TC - O(N log N) *  O(N * log(max(stalls[])-min(stalls[]))), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows>=cows)return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(canWePlace(stalls, mid, cows)==true){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
