// Longest Subarray with given Sum K(Positives)
// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.


//Brute Force
#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> a, long long k){
    int n = a.size();
    int maxlen = INT_MIN;
    for(int i=0;i<n;i++){
        long long s = 0;
        for(int j=0;j<n;j++){
            s += a[j];
            if(s == k){
                maxlen = max(maxlen,j-i+1);
            }
            else if(s>k)break;
        }
    }
    return maxlen;
}

int main(){
  vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

//Optimal: Sliding Window Technique
#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> a, long long k){
    int windowStart = 0;
    long long cur_sum = 0;
    int maxlen = INT_MIN;
    int n = a.size();
    for(int windowEnd=0;windowEnd<n;windowEnd++){
            cur_sum += a[windowEnd];
            while(windowStart<=windowEnd && cur_sum>k){
                cur_sum -= a[windowStart];
                windowStart++;
            }
            if(cur_sum==k){
                maxlen = max(maxlen, windowEnd-windowStart+1);
                cout<<maxlen<<endl;
            } 
    }
    return maxlen;
}

int main(){
  vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
