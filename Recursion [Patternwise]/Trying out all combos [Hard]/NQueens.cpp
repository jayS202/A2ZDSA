// Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

// Solution 1
// Time Complexity: O(N! * N) nearly.
// Space Complexity: O(N^2)  

// Input: 4
// Output:
// ..Q. Q... ...Q .Q.. 
// .Q.. ...Q Q... ..Q.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool Safe1(int col, int row, vector<string> &board, vector<vector<string>> &ans, int n){
            int duprow = row;
            int dupcol = col;
            
            while(row>=0 && col>=0){
                if(board[row][col] == 'Q')return false;
                row--;
                col--;
            }
            
            col = dupcol;
            row = duprow;
            
            while(col>=0){
                if(board[row][col] == 'Q')return false;
                col--;
            }
            
            col = dupcol;
            row = duprow;
            
            while(row<n && col>=0){
                if(board[row][col] == 'Q')return false;
                row++;
                col--;
            }
            
            return true;
        }
    
        void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
            if(col == n){
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(Safe1(col, row, board, ans, n)){
                    board[row][col] = 'Q';
                    solve(col+1, board, ans, n);
                    board[row][col] = '.';
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n){
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n, '.');
            for(int i=0;i<n;i++){
                board[i] = s;
            }
            solve(0, board, ans, n);
            return ans;
        }
};

int main()
{
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

// Solution 2
// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void solve(int col, vector<int> &lowerRow, vector<int> &upperDiagnol, vector<int> &lowerDiagnol, vector<string> &board, vector<vector<string>> &ans, int n){
            if(col == n){
                ans.push_back(board);
                return;
            }
            
            for(int row=0;row<n;row++){
                if(lowerRow[row]==0 && upperDiagnol[(n-1)+(col-row)]==0 && lowerDiagnol[row+col]==0){
                    board[row][col] = 'Q';
                    lowerRow[row] = 1;
                    upperDiagnol[(n-1)+(col-row)] = 1;
                    lowerDiagnol[row+col] = 1;
                    solve(col+1, lowerRow, upperDiagnol, lowerDiagnol, board, ans, n);
                    board[row][col] = '.';
                    lowerRow[row] = 0;
                    upperDiagnol[(n-1)+(col-row)] = 0;
                    lowerDiagnol[row+col] = 0;
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n){
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n, '.');
            for(int i=0;i<n;i++){
                board[i] = s;
            }
            vector<int> lowerRow(n, 0), upperDiagnol((2*n)-1, 0), lowerDiagnol((2*n)-1, 0);
            solve(0, lowerRow, upperDiagnol, lowerDiagnol, board, ans, n);
            return ans;
        }  
};

int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
