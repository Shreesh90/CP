#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
vector<pair<int, int> > G[100001];
vector<int> path;
int vis[200001];
stack<int> st;
int in[100001], out[100001];
int n, m;

void dfs(int x){
    vis[x] = 1;
    for(auto it : G[x]){
        int c = it.first;
        if(!vis[c]) dfs(c);
    }
    return;
}

bool connected(){
    dfs(1);
    for(int i=1;i<=n;i++){
        if(vis[i] == 0 and G[i].size() > 0) return false;
    }
    return true;
}

bool isEulerian(){

    if(!connected()) return 0;

    int startNodes=0;
    int endNodes=0;
    for(int i=1;i<=n;i++){
        int outer = out[i] - in[i];
        int inner = in[i] - out[i];
        if(outer > 1 || inner > 1) return false;
        else if(outer == 1) startNodes++;
        else if(inner == 1) endNodes++;
    }
    return (endNodes==0 and startNodes==0) or (endNodes==1 and startNodes==1);
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
                f=1;
                break;
            }
        }
        if(!f) {path.pb(v); st.pop();}
    }

}

int32_t main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        G[a].pb({b, i});
        out[a]++;
        in[b]++;
    }

    if(!isEulerian()){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    
    dfs1(1);

    reverse(path.begin(), path.end());

    if(path[path.size() - 1] != n) cout<<"IMPOSSIBLE";
    else for(int x: path) cout<<x<<" ";
}