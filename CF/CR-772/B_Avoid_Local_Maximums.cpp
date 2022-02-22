#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);

        for(ll i=0;i<n;i++) cin>>A[i];

       ll ret = 0;
       for(ll i=1;i<n-1;i++){
           if(A[i] > A[i-1] && A[i] > A[i+1]){
               ret++;
               ll prev = A[i];
               ll next = i+2 >= n ? 0 : A[i+2];
               A[i+1] = max(prev, next);
           }
       }
       cout<<ret<<"\n";
        for(ll i=0;i<n;i++) cout<<A[i]<<" ";
       cout<<"\n";
    }
}