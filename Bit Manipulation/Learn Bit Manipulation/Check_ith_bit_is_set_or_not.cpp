// Check if ith bit is a set or not

// Using left shift
// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void CheckiBitIsSetOrNot(int n, int i){
    if((n & (1<<i)) != 0){
        cout<<"ith bit is a set";
    }else{
        cout<<"ith bit is not a set";
    }
}

int main()
{
    int n = 1101;
    int i = 2;
    CheckiBitIsSetOrNot(n, i);
    return 0;
}


// Using right shift
// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void CheckiBitIsSetOrNot(int n, int i){
    if((n>>i) & 1) != 0){
        cout<<"ith bit is a set";
    }else{
        cout<<"ith bit is not a set";
    }
}

int main()
{
    int n = 1101;
    int i = 2;
    CheckiBitIsSetOrNot(n, i);
    return 0;
}
