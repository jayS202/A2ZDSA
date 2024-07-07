#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
            if(flag = 0) break;
        }
    }
    for(auto it: arr){
        cout<<it<<" ";
    }
} 
 
int main(){
    vector<int> arr = {3,5,2,6,1};
    int n = arr.size();
    bubblesort(arr, n);
    return 0;
}
