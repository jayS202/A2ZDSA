//Rearrange Array Elements by Sign
//Variety 1 - Equal number of positive and negative elements

//Brute
//TC - O(N+N/2) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n){
    vector<int> pos, neg;
    for(int i=0;i<n;i++){
        if(A[i]>=0){
            pos.push_back(A[i]);
        }
        else{
            neg.push_back(A[i]);
        }
    }
    for(int i=0;i<(n/2);i++){
        A[2*i]=pos[i];
        A[(2*i)+1]=neg[i];
    }
    return A;
}

int main(){
  vector<int> A {1,2,-4,-5};
  int n = A.size();
  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

//Optimal
//TC-O(N) SC-O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n){
    vector<int> arr(n,0);
    int posIndex=0, negIndex=1;
    for(int i=0;i<n;i++){
        if(A[i]>0){
            arr[posIndex]=A[i];
            posIndex += 2;
        }else{
            arr[negIndex]=A[i];
            negIndex += 2;
        }
    }
    return arr;
}

int main(){
  vector<int> A {1,2,-4,-5};
  int n = A.size();
  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}


//Variety 2 - Unequal number of positive and negative elements

//Brute
//TC - O(N) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n){
    vector<int> pos, neg;
    for(int i=0;i<n;i++){
        if(A[i]>=0){
            pos.push_back(A[i]);
        }else{
            pos.push_back(A[i]);
        }
    }
    
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            A[2*i]=pos[i];
            A[(2*i)+1]=neg[i];
        }
        int index = 2*neg.size();
        for(int i=neg.size();i<pos.size();i++){
            A[index]=pos[i];
            index++;
        }
    }else{
        for(int i=0;i<pos.size();i++){
            A[2*i]=pos[i];
            A[(2*i)+1]=neg[i];
        }
        int index = 2*pos.size();
        for(int i=pos.size();i<neg.size();i++){
            A[index]=neg[i];
            index++;
        }
    }
    return A;
}

int main(){
  vector<int> A {1,-3,2,-1,4,5};
  int n = A.size();
  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

}
