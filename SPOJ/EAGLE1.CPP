#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<pair<int, int> > G[100001];
int vis[100001];
int d[100001];
int d2[100001];
int n, t;

int dfs(int x, int wt, int d[]){
    vis[x] = 1;

    for(auto it: G[x]){
        int y = it.first;
        int w = it.second;
        if(!vis[y]){
            d[x] = max(d[x], w + wt);
            dfs(y, wt + w, d);
        }
    }
    d[x] = wt;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){ 
            G[i].clear();
            vis[i] = 0;
            d[i] = 0;
            d2[i] = 0;
        }

        for(int j=1;j<=n-1;j++){
            int a,b,w;
            cin>>a>>b>>w;
            G[a].pb({b, w});
            G[b].pb({a, w});
        }

        dfs(1, 0, d);
        for(int i=1;i<=n;i++) vis[i] = 0;
        dfs(n, 0, d2);

        for(int i=1;i<=n;i++){
            d[i] = max(d[i], d2[i]);
            cout<<d[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}