// Swap Two Numbers

// TC - O(1), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

pair<int, int> swap2Numbers(int a, int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a,b};
}

int main()
{
    int a;
    int b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
    pair<int, int> swapped = swap2Numbers(a, b);
    a = swapped.first;
    b = swapped.second;
    
    cout<<"\n";
    cout<< "Swapped A: "<<a<<"\n";
    cout<< "Swapped B: "<<b;
    return 0;
}
