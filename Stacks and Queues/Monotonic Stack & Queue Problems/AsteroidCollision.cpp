// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// TC - O(N), SC - O(N)
// Using Stack
#include<bits/stdc++.h>
using namespace std;

stack<int> AstroidCollision(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            // Positive
            st.push(arr[i]);
        }else{
            // Negative
            while(!st.empty() && st.top()>0 && st.top()<abs(arr[i])) st.pop();
            if(!st.empty() && st.top() == abs(arr[i])) st.pop();
            else if (st.empty() || st.top()<0) st.push(arr[i]);
        }
    }
    return st;
}

int main(){
    vector<int> arr = {4,7,1,1,2,-3,-7,17,15,-18,-20};
    stack<int> res = AstroidCollision(arr);
    if(res.empty()){
        cout<<"[]";
    }else{
        while(!res.empty()){
            cout<<res.top()<<" ";
            res.pop();
        }
    }
    return 0;
}



// TC - O(N), SC - O(N)
// Using Vector
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> st;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                // Positive
                st.push_back(arr[i]);
            }else{
                // Negative
                while(!st.empty() && st.back()>0 && st.back()<abs(arr[i])) st.pop_back();
                if(!st.empty() && st.back() == abs(arr[i])) st.pop_back();
                else if(st.empty() || st.back()<0) st.push_back(arr[i]);
            }
        }
        return st;
    }
};
