#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<pair<ll, ll> > G[100001];
int processed[100001];

int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll x, y, w;
        cin>>x>>y>>w;
        G[x].pb({y, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> > , greater<pair<ll, ll> > > pq;

    vector<ll> dist(n+1, LLONG_MAX);
    pq.push({0, 1});
    dist[1]=0;
    while(!pq.empty()){
        ll curr = pq.top().second;
        ll curr_d = pq.top().first;
        pq.pop();
        processed[curr] = 1;

        if(dist[curr] < curr_d) continue;
        for(auto edge: G[curr]){
            if(processed[edge.first]) continue;
            ll d = dist[curr] + edge.second;
            if(d < dist[edge.first]){
                dist[edge.first] = d;
                pq.push({dist[edge.first], edge.first});
            }
            
        }
    } 

    for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
}

