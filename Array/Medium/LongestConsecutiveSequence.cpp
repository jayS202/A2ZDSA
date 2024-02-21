// Longest Consecutive Sequence in an Array
// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

// Brute
// TC - O(N^3) SC - O(1)
#include<bits/stdc++.h>
using namespace  std;

bool ls(vector<int> a, int num){
    for(int i=0;i<a.size();i++){
        if(a[i] == num){
            return true;
        }
    }
    return false;
}

int longestSuccessiveElements(vector<int> a){
    int n = a.size();
    int longest = INT_MIN;
    for(int i=0;i<n;i++){
        int cnt = 1;
        int x = a[i];
        while(ls(a, x+1) == true){
            cnt = cnt + 1;
            x = x+1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

// Better
// TC - O(N log N) SC - O(N)
#include<bits/stdc++.h>
using namespace  std;

int longestSuccessiveElements(vector<int> a){
   int n = a.size();
   int curcnt = 0;
   int lastele = INT_MIN;
   int longest = 1;
   sort(a.begin(), a.end());
   for(int i=0;i<n;i++){
       if(a[i]-1 == lastele){
           curcnt = curcnt + 1;
           lastele = a[i];
       }
       else if(a[i] != lastele) {
           curcnt = 1;
           lastele = a[i];
       }
       longest = max(longest, curcnt);
   }
   return longest;
}

int main(){
    vector<int> a = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}


// Optimal
// TC - O(N) + O(2*N) ~ O(3*N)  SC - O(N)
#include<bits/stdc++.h>
using namespace  std;

int longestSuccessiveElements(vector<int> a){
    unordered_set<int> st;
    int longest = 1;
    for(int i=0;i<a.size();i++){
        st.insert(a[i]);
    }
    
    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x + 1)!= st.end()){
                cnt = cnt + 1;
                x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> a = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
