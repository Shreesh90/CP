#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod = 998244353;

void backtrack(vector<ll> &v, ll start, vector<vector<ll> > &ans, vector<ll> &temp){
    ans.pb(temp);    

    for(ll i=start;i<v.size();i++){
        temp.pb(v[i]);
        backtrack(v, i+1, ans, temp);
        temp.pop_back();
    }
}

ll XOR(vector<ll> &vec){
    ll xoro = 0;
    for(int e: vec){
        xoro = (xoro%mod) ^ (e%mod);
    }
    return xoro;
}

int main(){
    ll n,q;cin>>n;
    vector<ll> v;
    
    for(ll i=0;i<n;i++){
        ll x; cin>>x;
        v.pb(x);
    }
    vector<vector<ll> > ans;
    vector<ll> temp;
    backtrack(v, 0, ans, temp);
    cin>>q;
    while(q--){
        ll k; cin>>k;
        ll sum = 0;    
        for(int i=0;i<ans.size();i++){
            if(ans[i].size() <= k){
                ll xoro = XOR(ans[i]);
                sum += (xoro%mod);
                sum = sum%mod;
            }
        }
        cout<<sum<<endl;

    }
}