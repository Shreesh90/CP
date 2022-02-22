#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    return a.second >= b.first;
}
int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> monster(n), spell(n);

        for(ll i=0;i<n;i++) cin>>monster[i];
        for(ll i=0;i<n;i++) cin>>spell[i];

        vector<pair<ll, ll>> v;

        for(ll i=0;i<n;i++){
            v.push_back({monster[i] - spell[i] + 1, monster[i]});
        }
        sort(v.begin(), v.end());

        pair<ll, ll> temp = v[0];
        vector<pair<ll, ll>> ans;
        for(ll i=0;i<v.size();i++){
            if(cmp(temp, v[i])){
                temp.first = min((ll)temp.first, (ll)v[i].first);
                temp.second = max((ll)temp.second, (ll)v[i].second);
            }
            else {
                ans.push_back(temp);
                temp = v[i];
            }
        }
        ans.push_back(temp);
        ll ret = 0;
        for(auto it: ans){
            ll d = it.second - it.first+1;
            ret += (d*(d+1))/2;
        }
        cout<<ret<<"\n";
    }
}