// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Brute
// TC -  O(N2), where N = size of the given array. SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr){
    vector<int> ls;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int cnt = 0;
        if(ls.size() == 0 || ls[0]!=arr[i]){
            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]){
                    cnt++;
                }
            }
            if(cnt>(n/3)){
                ls.push_back(arr[i]);
            }
        }
        if(ls.size()==2)break;
    }
    return ls;
}

int main(){
    vector<int> arr = {1,1,1,1,3,2,2,2};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}

// Better
// TC - O(N*logN), where N = size of the given array. SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr){
    unordered_map<int,int> mpp;
    vector<int> ls;
    int n = arr.size();
    int mini = (int)(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){
            ls.push_back(arr[i]);
        }
        if(ls.size()==2)break;
    }
    return ls;
}

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11, 34};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}

// Optimal
// TC - O(N) + O(N), where N = size of the given array. SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr){
    int n = arr.size();
    vector<int> ls;
    int cnt1=0, cnt2 =0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i] != ele2){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2==0 && arr[i] != ele1){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(ele1==arr[i]){
            cnt1++;
        }
        else if(ele2==arr[i]){
            cnt2++;
        }
        else{
            cnt1--,cnt2--;
        }
    }
    
    int cnt3=0, cnt4=0;
    for(int i=0;i<n;i++){
        if(arr[i] == ele1) cnt3++;
        if(arr[i] == ele2) cnt4++;
    }
    if(cnt3 >= (int)(n/3) + 1) ls.push_back(ele1);
    if(cnt4 >= (int)(n/3) + 1) ls.push_back(ele2);
    
    return ls;
}

int main(){
    vector<int> arr = {1,1,1,1,3,2,2,2};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
