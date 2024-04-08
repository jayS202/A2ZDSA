// Capacity to Ship Packages within D Days
// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.


// Brute
// Time Complexity: O(N * (sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
// Reason: We are using a loop from max(weights[]) to sum(weights[]) to check all possible weights. Inside the loop, we are calling findDays() function for each weight. Now, inside the findDays() function, we are using a loop that runs for N times.
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &weights, int cap){
    int n = weights.size();
    int day = 1; int load = 0;
    for(int j=0;j<n;j++){
        if(load + weights[j]>cap){
            day = day + 1;
            load = weights[j];
        }else{
            load += weights[j];
        }
    }
    return day;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    for(int i=low;i<=high;i++){
        int noOfDays = 0;
        noOfDays = func(weights,i);
        if(noOfDays<=d){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}

// Optimal
// Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
// Reason: We are applying binary search on the range [max(weights[]), sum(weights[])]. For every possible answer ‘mid’, we are calling findDays() function. Now, inside the findDays() function, we are using a loop that runs for N times.
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &weights, int cap){
    int n = weights.size();
    int day = 1; int load = 0;
    for(int j=0;j<n;j++){
        if(load + weights[j]>cap){
            day = day + 1;
            load = weights[j];
        }else{
            load += weights[j];
        }
    }
    return day;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid = (low + high)/2;
        if(func(weights, mid) <= d){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
