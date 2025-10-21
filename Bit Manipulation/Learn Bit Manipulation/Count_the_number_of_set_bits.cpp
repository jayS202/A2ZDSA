// Count the number of set bits

// Approach 1
// TC - O(log2 N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int checkTheNumOfSetBits(int n){
    int cnt = 0;
    while(n!=1){
        if(n%2 == 1)cnt++;
        n = n/2;
    }
    if(n == 1)cnt+=1;
    return cnt;
}

int main()
{
    int n = 9;
    cout<<checkTheNumOfSetBits(n);
    return 0;
}

// Approach 2
// TC - O(log2 N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int checkTheNumOfSetBits(int n){
    int cnt = 0;
    while(n!=0){
        if(n&1)cnt++;
        n = n>>1;
    }
    return cnt;
}

int main()
{
    int n = 31;
    cout<<checkTheNumOfSetBits(n);
    return 0;
}

//  Approach 3 - Brian Kernighan’s Algorithm
// TC - O(Number of sets), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int checkTheNumOfSetBits(int n){
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

int main()
{
    int n = 13;
    cout<<checkTheNumOfSetBits(n);
    return 0;
}
