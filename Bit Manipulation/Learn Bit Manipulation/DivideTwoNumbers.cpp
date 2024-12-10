// Problem Statement
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
// Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

// Brute Force
// Time Complexity: O(D / d), where D is the dividend and d is the divisor.
// Space Complexity: O(1), as the algorithm uses a fixed amount of extra space.
#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(dividend == divisor)return 1;
    int sum = 0;
    int cnt = 0;
    while(sum+divisor<=dividend){
        cnt++;
        sum+= divisor;
    }
    return cnt;
}

int main()
{
    int numerator = 22;
    int denominator = 3;
    cout<<divide(numerator, denominator);
    return 0;
}

// Optimal
// TC - O(log2 N)^2 , SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(dividend == divisor)return 1;
    bool sign = true;
    if(dividend>=0 && divisor<0)sign = false;
    if(dividend<=0 && divisor>0)sign = false;

    long n = abs(dividend);
    long d = abs(divisor);

    long ans = 0;
    while(n>=d){
        int cnt = 0;
        while(n >= (d<<cnt+1)){
            cnt+=1;
        }
        ans+= (1<<cnt);
        n -= (d<<cnt);
    }
    if(ans==(1<<31) && sign)return INT_MAX;
    if(ans==(1<<31) && !sign)return INT_MIN;

    return sign ? ans : -ans;
    
}

int main()
{
    int numerator = 22;
    int denominator = 3;
    cout<<divide(numerator, denominator);
    return 0;
}
