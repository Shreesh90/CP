#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> G[100001], T[100001];
vector<int> order, ssc;
vector<vector<int> > sscs;
int vis[100001];
int n,m,x;

void dfs(int x){
    vis[x] = 1;
    for(int c: G[x]){
        if(!vis[c]) dfs(c);
    }
    order.pb(x);
}

void dfs1(int x){
    vis[x] = 1;
    for(int c: T[x]){
        if(!vis[c]) dfs1(c);
    }
    ssc.pb(x);
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        G[a].pb(b);
        T[b].pb(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }

    for(int i=1;i<=n;i++) vis[i]=0;

    int cc=0;
    
    for(int i=1;i<=n;i++){
        if(!vis[order[n-i]]){
            ssc.clear();
            dfs1(order[n-i]);
            sscs.pb(ssc);
            cc++;
        }
    }

    if(cc==1) cout<<"YES";
    else {
        cout<<"NO\n";
        cout<<sscs[1][0]<<" "<<sscs[0][0];
    }
}