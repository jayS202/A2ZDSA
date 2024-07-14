#include<bits/stdc++.h>
using namespace std;
 

void insertionsort(vector<int> arr, int n){
    for(int i=1;i<n;i++){
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

   
    for(auto it: arr){
        cout<<it<<" ";
    }
}
 

int main(){
    vector<int> arr = {13,46,24,52,20,9};
    int n = arr.size();
    insertionsort(arr, n);
    return 0;
}
