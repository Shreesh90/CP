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
        ll odd = 0, even=0;
        ll one = 0;
        for(ll i=1;i<n-1;i++){
            if(A[i] == 1) one++;
            if(A[i]%2 == 1) odd++;
            else even++;
        }

        if(odd == 1 && even==0) ret = -1;
        else if(odd == one && even == 0) ret = -1;
        else {
            for(ll i=1;i<n-1;i++){
                ret += (A[i]+1)/2;
            }
        }
        cout<<ret<<"\n";
    }
}