//Problem Statement: Second Largest Element in an Array

//Brute force: sort the array element and find the second largest using for loop
//Time Complexity: sort(n log n) for-loop(n) -> n + n log n.
#include<bits/stdc++.h>
using namespace std;

int secondlargestele(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    int largest = arr[n-1];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    vector<int> arr;
    arr = {3,4,6,8,4,12,5,9};
    int n = arr.size();
    cout<<secondlargestele(arr, n)<<endl;
    return 0;
}

//Better: a)find the largest element in array using for loop  
//        b) find the second largest element using another for loop
// Time Complexity: two for-loops(n+n) -> 2n.

#include<bits/stdc++.h>
using namespace std;

int secondlargestele(vector<int> arr, int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    vector<int> arr;
    arr = {3,4,6,8,4,12,5};
    int n = arr.size();
    cout<<secondlargestele(arr, n)<<endl;
    return 0;
}


//Optimal: a) Take largest and slargest as variables and traverse thrugh an array.
//         b) if( arr[i]>largest, slargest = largest, largest = arr[i]
#include<bits/stdc++.h>
using namespace std;

int secondlargestele(vector<int> arr, int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    vector<int> arr;
    arr = {3,4,6,8,4,12,5,7,10};
    int n = arr.size();
    cout<<secondlargestele(arr, n)<<endl;
    return 0;
}
