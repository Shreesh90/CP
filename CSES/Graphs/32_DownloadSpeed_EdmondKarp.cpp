#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

int cap[501][501];
vector<int> G[501];
vector<int> par(501);
int n, m;

int bfs(int s, int t){
    fill(par.begin(), par.end(), -1);

    par[s] = -2;
    queue<pair<int, int> > q;
    q.push({s, LLONG_MAX});

    while(!q.empty()){
        int curr = q.front().first;
        int currd = q.front().second;
        q.pop();
        
        int rep, pre=-2;
        for(int c: G[curr]){
            // rep = c;
            if((c == pre) or (par[c] == -1 && cap[curr][c])){
                par[c] = curr;
                int new_flow = min(currd, cap[curr][c]);
                if(c == t){
                    return new_flow;
                }
                q.push({c, new_flow});
            }
            pre = c;
        }
    }
    return 0;
}

int maxflow(int s, int t){
    int flow = 0;
    int new_flow;

    while((new_flow) = (bfs(s, t))){
        flow += new_flow;
        int curr = t;

        while(curr != s){
            int p = par[curr];
            cap[p][curr] -= new_flow;
            cap[curr][p] += new_flow;
            curr = p;
        }
    }
    return flow;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin>>a>>b>>w;
        G[a].pb(b);
        G[b].pb(a);
        cap[a][b] = w;
    }

    cout<<maxflow(1, n);
}