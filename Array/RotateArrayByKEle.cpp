//Problem Statement: Check if the given array is sorted.

//Brute force
//Time Complexity: O(n)
//Space Complexity: O(k) since k array element needs to be stored in temp array

#include<bits/stdc++.h>
using namespace std;

void LeftRotate(int *arr, int n, int d){
      // d=16 , d=16%7, d=2, Rotate left by 2 
      d = d % n;
      //Storing first 'd' elements in temp (Storing)
      int temp[d];
      for(int i=0;i<d;i++){
          temp[i] = arr[i];
      }

      //Shifting the remaining elements to the left (Shifting)
      for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
      }

      // Appendng the reamining element from the temp to array arr (Appending)
      int j=0;
      for(int i=n-d;i<n;i++){
        arr[i]=temp[j++];
        //arr[i] = temp[i-(n-d)];
      }

      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
}

//Store first 'd' elements to temp and append to last
void RightRotate(int *arr, int n, int d){
      // d=16 , d=16%7, d=2, Rotate left by 2 
      d = d % n;
      //Storing first 'd' elements in temp (Storing)
      int temp[n-d];
      for(int i=0;i<n-d;i++){
          temp[i] = arr[i];
      }

      //Shifting the remaining elements to the left (Shifting)
      int j=0;
      for(int i=n-d;i<n;i++){
        arr[j++] = arr[i];
      }

      // Appendng the reamining element from the temp to array arr (Appending)
      int k=0;
      for(int i=j;i<n;i++){
        arr[i]=temp[k++];
        //arr[i] = temp[i-(n-d)];
      }

      //Print the output
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
}

//Store last 'd' elements to temp append to first
void RightRotate(int *arr, int n, int d){
    d = d%n;
    //Storing first 'd' elements in temp (Storing)
    int temp[d];
    for(int i=n-d;i<n;i++){
        temp[i-(n-d)]=arr[i];
    }

    //Shifting the remaining elements to the right (Shifting)
    for(int i=n-d-1;i>=0;i--){
        arr[i+d]=arr[i];
    }

     // Appendng the reamining element from the temp to array arr (Appending)
    for(int i=0;i<d;i++){
      arr[i]=temp[i];
    }

    //Print the output
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
    RightRotate(arr, n, d);
    return 0;
}


//Optimal:

#include<bits/stdc++.h>
using namespace std;

void Reverse(int *arr, int start, int end){
  while(start<=end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void LeftRotate(int *arr, int n, int d){
  Reverse(arr,0,d-1);
  Reverse(arr,d,n-1);
  Reverse(arr,0,n-1);

  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
}

void RightRotate(int *arr, int n, int d){
  Reverse(arr,n-d,n-1);
  Reverse(arr,0,n-d-1);
  Reverse(arr,0,n-1);

  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 4;
    //LeftRotate(arr, n, d);    
    RightRotate(arr, n, d);
    return 0;
}
