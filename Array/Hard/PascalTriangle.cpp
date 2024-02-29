// Program to generate Pascal’s Triangle
// Problem Statement: This problem has 3 variations. They are stated below:

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}

int pascalnCr(int r, int c){
    int ele = nCr(r-1,c-1);
    return ele;
}

vector<int> pascalRow(int r){
    vector<int> ans;
    ans.push_back(1);
    int res = 1;
    for(int i=1;i<r;i++){
        res = res * (r-i);
        res = res/i;
        ans.push_back(res);
    }
    return ans;
}

void pascalTriangle(int r){
    vector<vector<int>> pascal;
    for(int c=1;c<=r;c++){
        pascal.push_back(pascalRow(c));
    }
    for(int i=0;i<pascal.size();i++){
        cout<<"\n";
        for(int j=0;j<pascal[i].size();j++){
            cout<<pascal[i][j]<<" ";
        }
    }
}


int main(){
    int r = 6; // row number
    int c = 3; // col number
    int element = pascalnCr(r, c);
    cout << "The element at position (r,c) is: "
            << element << "\n";
            
    vector<int> row = pascalRow(r);
    for(auto it: row){
        cout<<it<<" ";
    }
    
    pascalTriangle(r);
    return 0;
}
