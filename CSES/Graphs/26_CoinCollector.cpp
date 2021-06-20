#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

vector<int> G[100001], T[100001], RG[100001];
vector<int> order, base(100001, -1), dp(100001, 0), group(100001, 0);
vector<int> bases;
int coins[100001];
int vis[100001];
int n, m;
int ans=0;

void dfs(int x){
    vis[x] = 1;

    for(int c: G[x]){
        if(!vis[c]) dfs(c);
    }
    order.pb(x);
}

void dfs1(int x, int b){
    base[x] = b;
    for(int c: T[x]){
        if(base[c] == -1) dfs1(c, b);
    }
    
}

int DP(int b){
    if(dp[b] ) return dp[b];

    dp[b] = group[b];

    for(int c : RG[b]){
        dp[b] = max(dp[b], DP(c) + group[b]);
    }
    return dp[b];
}

int32_t main() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>coins[i];

    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        G[a].pb(b);
        T[b].pb(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }


    for(int i=1;i<=n;i++){
        if(base[order[n-i]] == -1){
            dfs1(order[n-i], order[n-i]);
            bases.pb(order[n-i]);
        }
    }

    for(int i=1;i<=n;i++){
        group[base[i]] += coins[i];
    }

    for(int i=1;i<=n;i++){
        for(int c: G[i]){
            if(base[c] == base[i]) continue;
            // This not necessarily needs to be a reverse condensed graph
            // RG[base[i]].pb(base[c]); ----> This will also get accept
            RG[base[c]].pb(base[i]);
        }
    }

    for(int b: bases){
        ans = max(ans, DP(b));
    }
    cout<<ans;
}