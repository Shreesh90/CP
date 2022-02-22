#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);

        for(int i=0;i<n;i++) cin>>A[i];

        int f=0;
        for(int i=1;i<n;i++){
            if(A[i] < A[i-1]) {
                f=1;
                break;
            }
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";

    }
}