#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<long, long>, bool> mp;

bool solve(ll a, ll b, ll x){
    if(labs(a-b) == x) return true;
    if(labs(a-b) < x) return false;
    // if(mp.find({a,b}) != mp.end()) return mp[{a,b}];
    // if(mp.find({b,a}) != mp.end()) return mp[{b,a}];
    int diff = labs(a-b);
    if(diff <= a) return solve(labs(a-b), b, x); 
    else return solve(a, labs(a-b), x);
    // mp[{a,b}] =  solve(labs(a-b), b, x) || solve(a, labs(a-b), x);
    // mp[{b,a}] =  solve(labs(a-b), b, x) || solve(a, labs(a-b), x);
    // return mp[{a,b}];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        ll a,b,x;
        cin>>a>>b>>x;
        if(solve(a,b,x)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}