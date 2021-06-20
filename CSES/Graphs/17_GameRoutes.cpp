#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<int> G[100001];
vector<set<int> > par(100001);
int dp[100001];
#define mod 1000000007

int paths(int x){
    
    if(dp[x] != -1) return dp[x];

    int ret=0;
    for(int p: par[x]){
        if(p == 1){
            (ret += 1) % mod;
        }
        else {
            (ret += paths(p)) %mod;
        }
    }
    return (dp[x] = ret) %mod;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        G[x].pb(y);
        par[y].insert(x);
    }

    par[1].insert(-1);
    cout<<paths(n);
}
