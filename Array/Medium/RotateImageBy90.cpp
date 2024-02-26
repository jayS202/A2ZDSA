// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

//Brute
//  TC - O(N*N)  SC - O(N*N)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> arr){
    int n = arr.size();
    vector<vector<int>> mat(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[j][(n-1)-i] = arr[i][j];
        }
    }
    return mat;
}

int main(){
    vector < vector < int >> arr;
    arr =  {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, { 13, 14, 15, 16}};
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
    }
}

// Optimal
// TC - O(N*N) + O(N*N) SC -  O(1)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i!=j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    
    return arr;
}

int main(){
    vector < vector < int >> arr;
    arr =  {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, { 13, 14, 15, 16}};
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
    }
}
