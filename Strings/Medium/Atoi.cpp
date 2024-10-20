// Problem Statement
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.


// TC - O(N) SC - (1)
#include <bits/stdc++.h>
using namespace std;

int Atoi(string s){
    int i = 0;
    long result = 0;
    while(i<s.length() && s[i]==' '){
        i++;
    }
    int sign = 1;
    if(i<s.length() && (s[i]=='-' || s[i]=='+')){
        (s[i]=='-')?sign = -1: sign = 1;
        i++;
    }
    
    while(i<s.length() && isdigit(s[i])){
        result = result * 10 + (s[i] - '0');
        // handle overflow and underflow
        if(result*sign>=INT_MAX)return INT_MAX;
        if(result*sign<=INT_MIN)return INT_MIN;
        i++;
    }
    return result*sign;
}

int main()
{
    string s = "-91283472332";
    int res = Atoi(s);
    cout<<res;
    return 0;
}


// Recursive implementation of Atoi
#include <bits/stdc++.h>
using namespace std;

int AtoiRec(string s, int n, int index, bool isNegative, int result){
    if(index==n || !isdigit(s[index])){
        return isNegative?-result:result;
    }

    int digit = s[index] - '0';
    if(result > (INT_MAX-digit)/10){
        isNegative? INT_MIN:INT_MAX;
    }
    
    result = result * 10 + digit;

    return AtoiRec(s, n, index+1, isNegative, result);
}

int myAtoi(string s) {
    int index = 0;
    int n = s.size();
    bool isNegative = false;
    int result = 0;
    while(index<n && s[index] == ' '){
        index++;
    }

    if(index<n && (s[index] == '-' || s[index] == '+')){
        isNegative = (s[index] == '-');
        index++;
    }

    return AtoiRec(s, n, index, isNegative, result);
}

int main()
{
    string s = "  -123abc ";
    int res = myAtoi(s);
    cout<<res;
    return 0;
}
