// Find the repeating and missing numbers
// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Brute
// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();
    int repeating= -1;
    int missing = -1;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(a[j]==i)cnt++;
            
        }
        if(cnt == 0) missing = i;
        else if(cnt == 2) repeating = i;
        if(missing != -1 && repeating!= -1){
            break;
        }
    }
    return {missing, repeating};
}

int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Better
// TC - O(2N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();
    long long hasharr[n+1] = {0};
    long long repeating = -1, missing = -1;
    for(int i=0;i<n;i++){
        hasharr[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hasharr[i] == 0) missing = i;
        if(hasharr[i] == 2) repeating = i;
    }
    return {(int)repeating, (int)missing};
}

int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Optimal
// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    long long n = a.size();
    long long y1 = (n * (n+1))/2;
    long long y2 = (n * (n+1) * (2*n+1))/6;
    long long x1 = 0;
    long long x2 = 0;
    for(int i=0;i<n;i++){
        x1 += a[i];
        x2 += (long long)a[i] * (long long)a[i];
    }
    long long var1 = x1-y1;
    long long var2 = x2-y2;
    var2 = var2/var1;
    
    long long x = (var1+var2)/2;
    long long y = x-var1;
    
    return {(int)x,(int)y};
}

int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
