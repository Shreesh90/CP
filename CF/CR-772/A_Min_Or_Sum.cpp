#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);

        for(int i=0;i<n;i++) cin>>A[i];

        sort(A.begin(), A.end());

        ll ret = 0;

        for(int i=0;i<n;i++){
            ret = ret | A[i];
        }
        cout<<ret<<"\n";
    }
}