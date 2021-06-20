#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<int> G[100002];
int visited[100002];
int par[100002];
int e, s;
vector<int> path;
int onStack[100002];

bool dfs(int x, int p=-1){
    visited[x]=1;
    par[x]=p;
    onStack[x] = 1;

    for(int c: G[x]){
        if(!visited[c]){
            if(dfs(c, x)) return true;
        }
        if(visited[c] and onStack[c]) {
            s = c;
            e = x;
            return true;
        }
    }

    onStack[x] = 0;
    return false;
}

void route(){
    int t=e;
    while(e != s){
        path.pb(e);
        e = par[e];
    }
    path.pb(s);
    path.pb(t);
    reverse(path.begin(), path.end());
}

int32_t main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        G[x].pb(y);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i)){
                route();
                cout<<path.size()<<endl;
                for(int x: path){
                    cout<<x<<" ";
                }
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";
}