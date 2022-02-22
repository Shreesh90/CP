#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t; cin>>t;
    while(t--){
        ll n,k; 
        cin>>n>>k;

        if(k==n-1){
            cout<<-1<<"\n";
        }
        else {
            vector<pair<ll, ll>> A;
            vector<ll> vis(n, 0);
            A.push_back({k,n-1});
            vis[k] = 1;
            vis[n-1] = 1;

            for(ll i=n-1;i>0;i--){
                if(!vis[i]){
                    ll a = i;
                    ll b = i ^ (n-1);
                    if(vis[b]) continue;
                    A.push_back({a,b});
                    vis[a] =1;
                    vis[b] =1;
                }
            }
            for(ll i=1;i<=n-1;i++){
                if(!vis[i]) {A.push_back({0,i}); break;}
            }

            for(ll i=0;i<A.size();i++){
                cout<<A[i].first<<" "<<A[i].second<<"\n";
            }

        }
        
    }
}