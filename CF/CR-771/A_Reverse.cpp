#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);

        for(ll i=0;i<n;i++) cin>>A[i];

        ll l=0,r=0;

        for(ll i=0;i<n;i++){
            if(A[i] != i+1){
                l = i;
                break;
            }
        }
        for(ll i=l;i<n;i++){
            if(A[i] == l+1){
                r = i;
                break;
            }
        }

        while(l<r){
            swap(A[l++], A[r--]);
        }
        for(ll i=0;i<n;i++) cout<<A[i]<<" ";
        cout<<"\n";
    }
}