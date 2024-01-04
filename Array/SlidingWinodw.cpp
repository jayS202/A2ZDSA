//Sliding Window Technique
//source: Ryan Schachte: https://youtu.be/MK-NZ4hN7rs?si=tjQj0QnyCxxXPCMK

//Q) Find the sum of each subarray of length 3
#include<bits/stdc++.h>
using namespace std;

vector<int> slidingwindow(vector<int> arr, int n, int k){
  vector<int> res;
  int ans = 0;
  for(int i=0;i<k;i++){
      ans += arr[i];
  }
  res.push_back(ans);
  
  for(int i=1;i<n-k+1;i++){
    ans = ans - arr[i-1];
    ans = ans + arr[i+k-1];
    res.push_back(ans);
  }
  return res;
}

int main(){
    vector<int> arr = {4,2,2,7,8,1,2,8,10};
    int n = arr.size();
    int k = 3;
    vector<int> ans = slidingwindow(arr,n,k);
    for(auto it: ans){
      cout<<it<<" ";
    }
    return 0;
} 

//Fixed Sliding Window
//Q) Find the max sum subarray of a fixed size k.
#include<bits/stdc++.h>
using namespace std;

int fixedslidingwindow(vector<int> arr, int n, int k){
  int currentSum = 0;
  int maxValue = INT_MIN;

  for(int i=0;i<n;i++){
    currentSum += arr[i];
    if(i>= k-1){
      maxValue = max(maxValue,currentSum);
      currentSum -= arr[i-(k-1)]; 
    }
  }
  return maxValue;
}

int main(){
    vector<int> arr = {4,2,2,7,8,1,2,8,10};
    int n = arr.size();
    int k = 3;
    cout<<fixedslidingwindow(arr,n,k)<<endl;
    return 0;
}

//Dynamic Sliding Window
//Q) Find the smallest Sliding Winodw
#include<bits/stdc++.h>
using namespace std;

int dynamicSlidingWindow(vector<int> arr, int n, int targetSum){
    int minWindowSize = INT_MAX;
    int currentWindowSum = 0;
    int windowStart = 0;
    for(int windowEnd=0;windowEnd<n;windowEnd++){
        currentWindowSum += arr[windowEnd];
        while(currentWindowSum >= targetSum){
          minWindowSize = min(minWindowSize,windowEnd - windowStart + 1);
          currentWindowSum -= arr[windowStart];
          windowStart++;
        }
    }
    return minWindowSize;
}

int main(){
    vector<int> arr = {4,2,2,7,8,1,2,8,10};
    int n = arr.size();
    int targetSum = 8;
    cout<<dynamicSlidingWindow(arr,n,targetSum);
    return 0;
}

