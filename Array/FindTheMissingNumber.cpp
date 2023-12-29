//Find the missing number in an array
//Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

//Brute 
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int N){
  for(int i=1;i<=N;i++){
    int flag = 0;
    for(int j=0;j<N-1;j++){
      if(arr[j]==i){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      return i;
    }
  }
}

int main(){
    int N = 5;
    vector<int> arr = {1, 2, 4, 5};
    int ans = missingNumber(arr, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}



//Brute Force
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int N){
  int hash[N] = {0};
  for(int i=0;i<N-1;i++){
    hash[arr[i]] = 1;
  }
  for(int i=1;i<=N;i++){
    if(hash[i]==0)return i;
  }
}

int main(){
    int N = 5;
    vector<int> arr = {1, 2, 4, 5};
    int ans = missingNumber(arr, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}



//Optimal 1
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int N){
  int sumofarr = (N*(N+1))/2;
  int s = 0;
  for(int i=0;i<N-1;i++){
      s = s + arr[i];
  }
  return sumofarr - s;
}

int main(){
    int N = 5;
    vector<int> arr = {1, 2, 4, 5};
    int ans = missingNumber(arr, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}


//Optimal 2
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int N){
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=1;i<=N;i++){
      XOR1 = XOR1^i;
    }
    for(int i=0;i<N-1;i++){
      XOR2 = XOR2^arr[i];
    }

    return XOR1^XOR2;
}

// int missingNumber(vector<int> arr, int N){
//     int XOR1 = 0;
//     int XOR2 = 0;  
//     for(int i=0;i<N-1;i++){
//       XOR2 = XOR2^arr[i];
//       XOR1 = XOR1^(i+1);
//     }
//     return XOR1^XOR2;
// }

int main(){
    int N = 5;
    vector<int> arr = {1, 2, 4, 5};
    int ans = missingNumber(arr, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
