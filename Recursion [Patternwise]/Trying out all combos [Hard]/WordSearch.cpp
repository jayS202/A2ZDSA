// Problem Statement: Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// TC - O(n * m * 4^L), SC - O(L)
#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<char>> &board, string word, int i, int j, int n, int m, int k){
    if(k == word.size())return true;
    if(i<0 || j<0 || i==n || j==m || board[i][j] != word[k])return false;
    
    char ch = board[i][j];
    board[i][j] = '#';
    bool op1 = search(board, word, i+1, j, n, m, k+1);
    bool op2 = search(board, word, i-1, j, n, m, k+1);
    bool op3 = search(board, word, i, j+1, n, m, k+1);
    bool op4 = search(board, word, i, j-1, n, m, k+1);
    board[i][j] = ch;
    
    return op1 || op2 || op3 || op4;
}

bool wordSearch(vector<vector<char>> &board, string word, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == word[0]){
                if(search(board, word, i, j, n, m, 0))return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    int n = board.size();
    int m = board[0].size();
    string word = "ABCED";
    bool res = wordSearch(board, word, n, m);
    (res)?cout<<"It is present in the board": cout<<"Not present in the board";
    return 0;
}
