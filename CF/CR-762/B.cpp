#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    vector<ll> A;
    map<ll, bool> vis;

    for(ll i=1;i*i<=1000000000;i++){
        if(!vis[i*i]){
            vis[i*i] = true;
            A.push_back(i*i);
        }
        if(!vis[i*i*i]){
            vis[i*i*i] = true;
            A.push_back(i*i*i);
        }
    }
    sort(A.begin(), A.end());

    int t; cin>>t;
    while(t--){
        ll x;
        cin>>x;
        cout<< upper_bound(A.begin(), A.end(), x) - A.begin() <<"\n";
    }
}