#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mod 1000000007
vector<int> G[100001];
int dp[20][1<<20];
int n, m;

int dfs(int x, int mask){
    if(__builtin_popcount(mask) == n) return 1;
    else if(x == n-1) return 0;

    if(dp[x][mask] != -1) return dp[x][mask];
    
    int res = 0;
    for(int c: G[x]){
        if(mask & (1<<c)) continue;
        res = (res%mod + dfs(c, mask | (1<<c)%mod))%mod;
    }
    return dp[x][mask] = res;
}

int32_t main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a, b; 
        cin>>a>>b;
        --a, --b;
        G[a].pb(b);
    }

    memset(dp, -1, sizeof(dp));
    cout<<dfs(0, 1<<0);

}