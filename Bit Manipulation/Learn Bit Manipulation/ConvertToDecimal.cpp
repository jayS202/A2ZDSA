// Convert Binary to Decimal number

// TC - O(n), SC - O(n)
#include<bits/stdc++.h>
using namespace std;

int convertToDecimal(string num){
    int len = num.size();
    int p2 = 1;
    int n = 0;
    for(int i=len-1;i>=0;i--){
        if(num[i] == '1'){
            n += p2;
        }
        p2 = p2*2;
    }
    return n;
}

int main()
{
    string n;
    cout<<"Binary Number: ";
    cin>>n;
    cout<<convertToDecimal(n);
    return 0;
}
