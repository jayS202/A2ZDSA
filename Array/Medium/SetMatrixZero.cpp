//Set Matrix Zero
//Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

//Brute
//TC - O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void row(vector<vector<int>> &matrix, int i, int m){
    for(int j=0;j<m;j++){
        if(matrix[i][j]!=0){
            matrix[i][j] =-1;
        }
    }
}

void col(vector<vector<int>> &matrix, int j, int n){
    for(int i=0;i<n;i++){
        if(matrix[i][j]!=0){
            matrix[i][j] =-1;
        }
    }
}


vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                row(matrix, i, m);
                col(matrix, j, n);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

//Better
// TC - O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// SC - O(N) + O(N)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> matrix, int n, int m){
    int col[m] = {0};
    int row[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

//Optimal
//TC - O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix. 
//SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    //col[0] -> matrix[i][0]
    //row[0] -> matrix[0][j]
    int col0 = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                
                if(j!=0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    if(matrix[0][0] == 0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
    
    return matrix;
}


int main(){
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1},{0, 1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
