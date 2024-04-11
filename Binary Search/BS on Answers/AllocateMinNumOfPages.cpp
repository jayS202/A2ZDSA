// Allocate Minimum Number of Pages

// Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1


// Brute
// TC = O(N * (sum(arr[])-max(arr[]+1)), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int allocate(vector<int> &arr, int n, int pages){
    int student = 1;
    long long pagesStudent = 0;
    
    for(int i=0;i<n;i++){
        if(pagesStudent + arr[i]<=pages){
            pagesStudent += arr[i];
        }else{
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m){
    if(m>n)return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    
    for(int pages=low;pages<=high;pages++){
        if(allocate(arr, n, pages) == m){
            return pages;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

// Optimal
// TC = O(N * log(sum(arr[])-max(arr[]+1)), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int allocate(vector<int> &arr, int n, int pages){
    int student = 1;
    long long pagesStudent = 0;
    
    for(int i=0;i<n;i++){
        if(pagesStudent + arr[i]<=pages){
            pagesStudent += arr[i];
        }else{
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m){
    if(m>n)return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    
    while(low<=high){
        int mid = (low+high)/2;
        if(allocate(arr,n,mid)<=m){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
