#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n; cin>>n;
    map<ll, ll> mp;
    
    for(ll i=0;i<n;i++){
        ll x; cin>>x;
        mp[x]++;
    }

    for(auto it: mp){
        if(it.second >= n/2) {cout<<it.first; break;}
    }

}