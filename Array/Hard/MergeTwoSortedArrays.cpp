// Brute
// TC -  O(n+m) + O(n+m), SC - O(n+m)
#include<bits/stdc++.h>
using namespace std;

void merge(long long *arr1, long long *arr2, int n, int m){
    int left = 0;
    int right = 0;
    long long arr3[n+m];
    int index = 0;
    while(left<n && right<m){
        if(arr1[left]<arr2[right]){
            arr3[index] = arr1[left];
            index++;left++;
        }else{
            arr3[index] = arr2[right];
            index++; right++;
        }
    }
    
    while(left<n){
        arr3[index++] = arr1[left++];
    }
    
    while(right<m){
        arr3[index++] = arr2[right++];
    }
    
    for(int i=0;i<(n+m);i++){
        if(i<n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}

int main(){
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}


// Optimal 1
// TC - O(min(n, m)) + O(n*logn) + O(m*logm), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void merge(long long *arr1, long long *arr2, int n, int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
        }else{
            break;
        }
        left--; right++;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main(){
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

// Optimal 2
// TC - O((n+m)*log(n+m)), SC - O(!)
#include<bits/stdc++.h>
using namespace std;

void swapgreater(long long *arr1, long long *arr2, int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}

void merge(long long *arr1, long long *arr2, int n, int m){
    int len = n+m;
    int gap = (len/2)+(len%2);
    while(gap>0){
        int left= 0;
        int right = left + gap;
        while(right<len){
            if(left<n && right>=n){
                swapgreater( arr1, arr2, left, right-n);
            }else if(left>=n){
                swapgreater( arr2, arr2, left - n, right  - n);
            }else{
                swapgreater( arr1, arr1, left, right);
            }
            left++; right++;
        }
        if(gap==1)break;
        gap = (gap/2)+(gap%2);
    }
}

int main(){
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
