// Rat in the maze
// Problem Statement - Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

// Solution n
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int row, int col, string move, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<string> &ans, int n){
        if(col == n-1 && row == n-1){
            ans.push_back(move);
            return;
        }
        
        // Downward
        if(row+1<n && !vis[row+1][col] && mat[row+1][col] == 1){
            vis[row][col] = 1;
            solve(row+1, col, move+'D', mat, vis, ans, n);
            vis[row][col] = 0;
        }
        
        // Leftward
        if(col-1>=0 && !vis[row][col-1] && mat[row][col-1] == 1){
            vis[row][col] = 1;
            solve(row, col-1, move+'L', mat, vis, ans, n);
            vis[row][col] = 0;
        }
        
        // Rightward
        if(col+1<n && !vis[row][col+1] && mat[row][col+1] == 1){
            vis[row][col] = 1;
            solve(row, col+1, move+'R', mat, vis, ans, n);
            vis[row][col] = 0;
        }
        
        // Upward
        if(row-1>=0 && !vis[row-1][col] && mat[row-1][col] == 1){
            vis[row][col] = 1;
            solve(row-1, col, move+'U', mat, vis, ans, n);
            vis[row][col] = 0;
        }
    }
  
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(mat[0][0]==1)solve(0, 0, "", mat, vis, ans, n);
        return ans;
    }
};

int main()
{
  int n = 4;
  vector < vector < int >> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  Solution obj;
  vector < string > result = obj.findPath(mat, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}


// Solution 2
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int row, int col, string move, int* Drow, int* Dcol, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<string> &ans, int n){
        if(col == n-1 && row == n-1){
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int i=0;i<4;i++){
            int nextrow = row + Drow[i];
            int nextcol = col + Dcol[i];
            
            if(nextrow>=0 && nextcol>=0 && nextrow<n && nextcol<n && !vis[nextrow][nextcol] && mat[nextrow][nextcol]==1){
                vis[row][col] = 1;
                solve(nextrow, nextcol, move+dir[i], Drow, Dcol, mat, vis, ans, n);
                vis[row][col] = 0;
            }
        }
    }
  
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int Drow[] = { 1, 0, 0, -1};
        int Dcol[] = { 0, -1, 1, 0};
        if(mat[0][0]==1)solve(0, 0, "", Drow, Dcol, mat, vis, ans, n);
        return ans;
    }
};

int main()
{
  int n = 4;
  vector < vector < int >> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  Solution obj;
  vector < string > result = obj.findPath(mat, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}
