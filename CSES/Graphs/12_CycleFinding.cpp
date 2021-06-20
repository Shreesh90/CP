#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

struct edge {
    ll a,b,w;
};

vector<edge> edges;


int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> d(n+1, INT_MAX);
    vector<ll> p(n+1, -1);
    
    for(int i=1;i<=m;i++){
        ll x, y, w;
        cin>>x>>y>>w;
        edge e = {x, y, w};
        edges.pb(e);
    }

    int flag = -1;
    d[1] = 0;
    for(ll i=1;i<=n;i++){
        flag = -1;

        for(ll j=0;j<=m-1;j++){
            ll x,y,z;
            x = edges[j].a;
            y = edges[j].b;
            z = edges[j].w;

            // if(d[x] == INT_MAX) continue;
            if(d[x] + z < d[y]){
                d[y] = min(d[y], d[x] + z);
                p[y] = x;
                flag = y;
            }
        }
    }

    // for(int x: p) cout<<x<<" ";

    if(flag == -1) cout<<"NO";
    else {
        cout<<"YES"<<endl;
        int y = flag;
        for(int i=1;i<=n;i++) y = p[y];

        vector<int> path;
        for(int cur=y; ; cur=p[cur]){
            path.pb(cur);
            if(cur == y && path.size() > 1) break;
        }

        reverse(path.begin(), path.end());

        for(int x: path) cout<<x<<" ";
    }   
}