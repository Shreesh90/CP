#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[100001], T[100001];
vector<int> order, ssc;
int kings[100001];
int vis[100001];
int n, m, k=0;

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
    kings[x] = k;
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        G[a].pb(b);
        T[b].pb(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof(vis));

    for(int i=1;i<=n;i++){
        if(!vis[order[n-i]]){
            k++;
            dfs1(order[n-i]);
        }
    }
    cout<<k<<endl;
    for(int i=1;i<=n;i++) cout<<kings[i]<<" ";
}