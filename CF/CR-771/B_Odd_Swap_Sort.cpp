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

        ll o=1,e=1;
        ll oddmax = 0, evenmax=0;

        for(ll i=0;i<n;i++){
            if(A[i]%2 == 0){
                if(A[i] >= evenmax){
                    evenmax = A[i];
                }
                else if(A[i] < evenmax){
                    e=0; break;
                }
            }
            else {
                if(A[i] >= oddmax) oddmax = A[i];
                else if(A[i] < oddmax){
                    o=0; break;
                }
            }
        }
        if(o && e) cout<<"Yes\n";
        else cout<<"No\n";
    }
}