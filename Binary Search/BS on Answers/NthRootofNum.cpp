// Brute
// TC - O(M), M = the given number., SC - O(1)
#include<bits/stdc++.h>
using namespace std;

long long power(int b,int expo){
    long long ans = 1;
    long long base = b;
    while(expo>0){
        if(expo%2){
            expo--;
            ans = ans * base;
        }else{
            expo /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m){
    for(int i=1;i<=m;i++){
        long long val = power(i,n);
        if(val == m*1ll)return i;
        else if(val > m*1ll)break;
    }
    return -1;
}


int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


// Optimal
// TC - O(logN), N = size of the given array., SC - O(1)
// This method of optimal solution works when there is integer overflow
#include<bits/stdc++.h>
using namespace std;

int power(int mid, int n, int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans * mid;
        if(ans > m)return 2;
    }
    if(ans == m)return 1;
    return 0;
}

int NthRoot(int n, int m){
  int low = 1, high = m;
  while(low<=high){
      int mid = (low+high)/2;
      int val = power(mid, n, m);
      if(val == 1){
          return mid;
      }
      else if(val==0){
          low = mid + 1;
      }else{
          high = mid - 1;
      }
  }
  return -1;
}


int main()
{
    int n = 9, m = 1953125;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
