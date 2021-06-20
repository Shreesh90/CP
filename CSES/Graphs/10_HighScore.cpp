#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int vis1[2501], vis2[2501];

struct edge {
    ll a,b,w;
};

vector<edge> edges;

void dfs(vector<vector<int> > &g,int x, int vis[]){
    vis[x]=1;
    for(auto c: g[x]){
        if(!vis[c]) dfs(g, c, vis);
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> d(n+1, INT_MAX);
    
    vector<vector<int> > a(2501), b(2501);

    for(int i=1;i<=m;i++){
        ll x, y, w;
        cin>>x>>y>>w;
        edge e = {x, y, w*(-1)};

        edges.pb(e);
        a[x].pb(y);
        b[y].pb(x);
    }
    
    dfs(a, 1, vis1);
    dfs(b, n, vis2);

    bool flag = false;
    d[1] = 0;
    for(ll i=1;i<=n;i++){
        flag = false;
        for(ll j=0;j<=m-1;j++){
            ll x,y,z;
            x = edges[j].a;
            y = edges[j].b;
            z = edges[j].w;
            if(d[x] == INT_MAX) continue;
            if(vis1[x] and vis2[y] and d[x] + z < d[y]){
                flag=true;
                d[y] = min(d[y], d[x] + z);
            }
        }
    }


    if(flag) cout<<-1;
    else cout<< ((d[n] == INT_MAX ? -1 : d[n]*-1)) ;

}