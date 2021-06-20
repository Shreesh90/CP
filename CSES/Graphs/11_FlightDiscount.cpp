#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<pair<ll, ll> > G[100001], Gi[100001];
int processed[100001], processed1[100001];
#define INF 1e18

int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll x, y, w;
        cin>>x>>y>>w;
        G[x].pb({y, w});
        Gi[y].pb({x, w});
    }


    priority_queue<pair<ll, ll>, vector<pair<ll, ll> > , greater<pair<ll, ll> > > pq;
    vector<ll> dist(n+1, INF);

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


    priority_queue<pair<ll, ll>, vector<pair<ll, ll> > , greater<pair<ll, ll> > > pq1;
    vector<ll> dist1(n+1, INF);
    pq1.push({0, n});
    dist1[n]=0;
    while(!pq1.empty()){
        ll curr = pq1.top().second;
        ll curr_d = pq1.top().first;
        pq1.pop();
        processed1[curr] = 1;

        if(dist1[curr] < curr_d) continue;
        for(auto edge: Gi[curr]){
            if(processed1[edge.first]) continue;
            ll d = dist1[curr] + edge.second;
            if(d < dist1[edge.first]){
                dist1[edge.first] = d;
                pq1.push({dist1[edge.first], edge.first});
            }
        }
    } 

    ll ans = INF;

    for(int i=1;i<=n;i++){
        for(auto c: G[i]){
            ll x = i;
            ll y = c.first;
            ll weight = c.second;

            if(dist[x] < INF and dist1[y] < INF){
                ans = min(ans, dist[x] + dist1[y] + weight/2);
            }
        }
    }

    cout<<ans;

}

