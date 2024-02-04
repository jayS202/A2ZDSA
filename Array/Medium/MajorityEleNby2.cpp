//Brute Force
Time Complexity: O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). Space Complexity: O(1) as we use no extra space.
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j])cnt++;
        }
        
        if(cnt>(n/2))return arr[i];
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

// Better
// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr){
    int n = arr.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    for(auto it: mp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

// Optimal approach
// Time Complexity: O(N) + O(N), where N = size of the given array.
// Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr){
    int n = arr.size();
    int cnt = 0;
    int ele;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            ele = arr[i];
        }
        else if(arr[i] == ele) cnt++;
        else cnt--;
    }
    
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>(n/2))return ele;
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
