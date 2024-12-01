// Convert To Binary - Convert the decimal to binary.

// TC - O(log n), SC - O(log n)
#include<bits/stdc++.h>
using namespace std;

string reverse(string str){
    int n = str.size();
    for(int i=0;i<n/2;i++){
        swap(str[i], str[n-i-1]);
    }
    return str;
}

string convertToBinary(int n){
    string str;
    while(n != 1){
        if(n%2 == 1){
            str+= '1';
        }else{
            str+= '0';
        }
        n = n/2;
    }
    if(n == 1)str += '1';
    string s = reverse(str);
    return s;
}

int main()
{
    int n;
    cout<<"Number: ";
    cin>>n;
    cout<<convertToBinary(n);
    return 0;
}
