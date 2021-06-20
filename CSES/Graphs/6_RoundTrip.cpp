#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<int> G[100001];
int visited[100001];
int par[100001];
int e, s;
vector<int> path;

bool dfs(int x, int p=-1){
    visited[x]=1;
    par[x]=p;

    for(int c: G[x]){
        if(!visited[c]){
            if(dfs(c, x)) return true;
        }
        else {
            if(c != p ) {
                s = c;
                e = x;
                return true;
            }
        }
    }

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
}

int32_t main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
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