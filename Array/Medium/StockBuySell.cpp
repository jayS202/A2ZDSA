//Stock Buy And Sell
//Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

//Optimal
//TC - O(N) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> arr){
    int n = arr.size();
    int profit=0;
    int mini= arr[0];
    for(int i=0;i<n;i++){
        int cost = arr[i]-mini;
        profit = max(profit,cost);
        mini = min(mini,arr[i]);
    }
    return profit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
