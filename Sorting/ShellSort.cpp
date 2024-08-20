#include<bits/stdc++.h>
using namespace std;

void shell_sort(int *arr, int n){
    for(int gap = n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]>arr[i]){
                    break;
                }else{
                    swap(arr[i+gap],arr[i]);
                }
            }
        }
    }
    
    cout << "After Using Shell Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Shell Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    shell_sort(arr, n);
    return 0;
}
