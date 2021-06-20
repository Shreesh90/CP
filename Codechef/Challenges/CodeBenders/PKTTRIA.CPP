#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1000000007;

ll power(ll x, ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2==1) ans = (ans*x) % mod;
        x = (x*x) % mod;
        n >>= 1;
    }
    return ans%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        n = n*8760*3600;
        cout<<power(2, n)<<"\n";
    }

}

