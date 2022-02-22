#include<bits/stdc++.h>
using namespace std;
#define ll long long

// map<pair<ll, ll>, bool> mp;

// bool solve(int v[], ll ind, ll alice, ll y, ll n){
//     if(ind == n){
//         if(alice == y) return true;
//         return false;
//     }
//     if(mp.find(make_pair(ind, alice)) != mp.end()) return mp[make_pair(ind, alice)];
//     return mp[make_pair(ind, alice)] = solve(v,ind+1, alice+v[ind],y,n) || solve(v,ind+1,alice^v[ind],y,n);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n,alice,y;
        cin>>n>>alice>>y;
        int v[n];

        int sum=0;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            sum += v[i];
        }

        if(sum%2 == 0){
            if(alice%2 == y%2) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else {
            if(alice%2 != y%2) cout<<"Alice\n";
            else cout<<"Bob\n";
        }

        ll bob = alice+3;



        // mp.clear();
        // bool a = solve(v,0,alice,y,n);
        // mp.clear();
        // bool b = solve(v,0,bob,y,n);
        // cout<<a<<" "<<b;
        // if(a) cout<<"Alice\n";
        // else cout<<"Bob\n";

    }
}