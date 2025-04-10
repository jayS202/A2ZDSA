#include<bits/stdc++.h>
using namespace std;

// TC - O(Q*N) where Q is number of Queries and N is size of the array.
int CountFrequencies(int num, vector<int> &arr){
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            cnt++;
        }
    }
    return cnt;
}

// TC - O(N) where N is the size of the array
void CountFrequencies(vector<int> &arr){
    int hash[13] = {0};
    // Pre-Storing
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }
    
    //Fetching
    int q;
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the element to be fetched: ";
        cin>>num;
        
        cout<<hash[num]<<"\n";
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 2};
    CountFrequencies(arr);
    return 0;
}
