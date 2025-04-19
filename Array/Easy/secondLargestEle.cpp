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





// Second Attempt
#include<bits/stdc++.h>
using namespace std;

// Better
// TC - O(N logN), SC - O(1)
void getElements(int *arr, int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    int largest = arr[n-1];
    cout<<"Largest: "<<largest<<"\n";
    int i=n-2;
    while(arr[i]==largest){
        i--;
    }
    
    if(i>=0){
        cout<<"Second Largest: "<<arr[i]<<"\n";
    }else{
        cout<<"Second Largest: Not found (all elements are equal)\n";
    }
    
    int smallest = arr[0];
    cout<<"Smallest: "<<smallest<<"\n";
    int j=1;
    while(arr[j]==smallest){
        j++;
    }
    
    if(j<n){
        cout<<"Second Smallest: "<<arr[j];
    }else{
        cout<<"Second Smallest: Not found (all elements are equal)\n";
    }
}

int main(){
    int arr[]={1,4,7,7,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}

// Optimal
#include<bits/stdc++.h>
using namespace std;

// TC - O(1), SC - O(1)
void getElements(int *arr, int n){
    int maxi = arr[0];
    int secMax = INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>maxi){
            secMax = maxi;
            maxi = arr[i];
        }
        else if(arr[i]>secMax && arr[i]!=maxi){
            secMax = arr[i];
        }
        cout<<"i: "<<i<<" - "<<arr[i]<<" "<<"maxi: "<<maxi<<" "<<"Sec Max: "<<secMax<<"\n";
    }
    
    cout<<"Largest: "<<maxi<<"\n";
    cout<<"Second Largest: "<<secMax<<"\n";
    
    int mini = arr[0];
    int secMin = INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<mini){
            secMin = mini;
            mini = arr[i];
        }else if(arr[i]<secMin && arr[i]!=mini){
            secMin = arr[i];
        }
        cout<<"i: "<<i<<" - "<<arr[i]<<" "<<"mini: "<<mini<<" "<<"Sec Min: "<<secMin<<"\n";
    }
    
    cout<<"Smallest: "<<mini<<"\n";
    cout<<"Second smallest: "<<secMin<<"\n";
}

int main(){
    int arr[]={1,4,7,7,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}
