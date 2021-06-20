#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<set<int> > G(100001);
int visited[100001];
int par[100001];

void bfs(int x, int p=-1){
    queue<int> q;
    visited[x] = 1;
    par[x] = p;
    q.push(x);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int c: G[curr]){
            q.push(c);
            visited[c] = 1;
            par[c] = curr;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        G[x].insert(y);
    }

    bfs(1);

    if(!visited[n]){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    int p = n;
    vector<int> path;
    
    while(p != -1){
        path.pb(p);
        p = par[p];
    }

    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(int x: path) cout<<x<<" ";

}