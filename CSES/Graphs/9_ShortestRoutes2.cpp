#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll> > G(501, vector<ll> (501, LLONG_MAX));

int main()
{
    ll n,m,q;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        G[i][i] = 0;
    }

    for(ll i=1;i<=m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        G[x][y] = G[y][x] = min(G[x][y], w);
    }

    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(G[i][k] < LLONG_MAX && G[k][j] < LLONG_MAX){
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
    }

    while(q--){
        ll a,b;
        cin>>a>>b;
        if(G[a][b] < 1e15) cout<<G[a][b]<<endl;
        else cout<< (G[a][b] = -1) <<endl;
    }
}

