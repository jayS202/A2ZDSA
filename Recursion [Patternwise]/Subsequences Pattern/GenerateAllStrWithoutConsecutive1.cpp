// Problem Statement: Given an integer, K. Generate all binary strings of size k without consecutive 1’s.

// Approach 1
// TC - O(2^N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void generate_all_strings(string st, int k){
    int len = st.size();
    if(len == k){
        cout<<st<<"\n";
        return;
    }
    else if(st[len-1] == '1'){
        generate_all_strings(st+'0', k);
    }else{
        generate_all_strings(st+'0', k);
        generate_all_strings(st+'1', k);
    }
}

void getAllStrings(int k){
    string st;
    st.push_back('0');
    generate_all_strings(st, k);
    st[0] = '1';
    generate_all_strings(st, k);
}

int main()
{
    int k = 4;
    getAllStrings(k);
    return 0;
}

// Approach 2
// TC - O(2^N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void generate_all_strings(char str[], int k, int len){
    if(len == k){
        str[len] = '\0';
        cout<<str<<"\n";
        return;
    }
    
    if(str[len - 1] == '1'){
        str[len] = '0';
        generate_all_strings(str, k, len+1);
    }
    
    if(str[len - 1] == '0'){
        str[len] = '0';
        generate_all_strings(str, k, len+1);
        str[len] = '1';
        generate_all_strings(str, k, len+1);
    }
}

void getAllStrings(int k){
    if(k<=0){
        return;
    }
    
    char str[k+1];
    str[0] = '0';
    generate_all_strings(str, k, 1);
    str[0] = '1';
    generate_all_strings(str, k, 1);
    
}

int main()
{
    int k = 4;
    getAllStrings(k);
    return 0;
}
