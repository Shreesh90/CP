#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<int, int> > G[100001];
vector<int> path;
stack<int> st;
int vis[200001];
int deg[100001];
int n, m;

void dfs(int x){
    vis[x] = 1;
    for(auto it : G[x]){
        int c = it.first;
        if(!vis[c]) dfs(c);
    }
}

bool connected(){
    dfs(1);
    for(int i=1;i<=n;i++){
        if(vis[i] == 0 and G[i].size() > 0) return false;
    }
    return true;
}

int isEuler(){
    if(!connected()) return 0;

    for(int i=1;i<=n;i++){
        if(deg[i] & 1) return 0;
    }
    return 1;
}

void dfs1(int x){
    st.push(x);
    while(!st.empty()){
        int v = st.top();
        int f=0;
        while(!G[v].empty()){       
            auto it = G[v].back();
            int c = it.first;
            int i = it.second;
            G[v].pop_back();
            if(!vis[i]){
                vis[i] = 1;
                st.push(c);
                f = 1;
                break;
            }
        }
        if(!f) {path.pb(v); st.pop();}
    }  
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        G[a].pb({b, i});
        G[b].pb({a, i});
        deg[a]++;
        deg[b]++;
    }

    // for(int i=1;i<=n;i++) sort(G[i].begin(), G[i].end());

    int ret = isEuler();

    if(ret == 0) cout<<"IMPOSSIBLE\n";
    else {
        memset(vis, 0, sizeof(vis));
        dfs1(1);
        if(path.size() != m+1) {cout<<"IMPOSSIBLE";}
        else for(int x: path) cout<<x<<" ";
    }
}   