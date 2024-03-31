// Brute
// TC - O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array., SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findMini(vector<int> v){
    int n = v.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}

int func(vector<int> v, int hourly){
    int totalhour = 0;
    for(int i=0;i<v.size();i++){
        totalhour += ceil((double)v[i]/(double)hourly);
    }
    return totalhour;
}

int minimumRateToEatBananas(vector<int> v, int h){
    int n = findMini(v);
    for(int i=1;i<=n;i++){
        int totalhour = func(v,i);
        if(totalhour <= h){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}


// Optimal
// TC - O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array., SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int findMaxi(vector<int> &v){
    int n = v.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}

int func(vector<int> &v, int hourly){
    int totalhours = 0;
    for(int i=0;i<v.size();i++){
        totalhours += ceil((double)v[i]/(double)hourly); 
    }
    return totalhours;
}

int minimumRateToEatBananas(vector<int> &v, int h){
    int n = findMaxi(v);
    int low = 1, high = n;
    while(low<=high){
        int mid = (low+high)/2;
        int totalhours = func(v,mid);
        if(totalhours<=h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
