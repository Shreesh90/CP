#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n, m;
vector<vector<int> > G(501, vector<int> (501, 0));
// vector<vector<int> > G(501, vector<int> (501, 0));
vector<int> level(501, -1);
vector<int> counter(501, 0);

bool bfs(int s, int t){
    fill(level.begin(), level.end(), -1);
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int c=1;c<=n;c++){
            if(curr != c and G[curr][c] > 0 and level[c] < 0){
                level[c] = level[curr] + 1;
                q.push(c);
            }
        }
    }

    return level[t] < 0 ? false : true;
}

int send_flow(int s, int t, int flow){
    if(s == t) return flow;

    if(counter[s] == G[s].size()) return 0;

    for(int c=1;c<=n;c++){
        if(G[s][c] > 0){
            counter[s]++;
            if(level[c] == level[s]+1){
                int curr_flow = min(flow, G[s][c]);
                int min_cap = send_flow(c, t, curr_flow);
                if(min_cap > 0){
                    G[s][c] -= min_cap;
                    G[c][s] += min_cap;
                    return min_cap;
                }
            }

        }
    }
    return 0;
}

int dinic(int s, int t){
    if(s==t) return -1;
    int max_flow = 0;
    // G = G;

    while(bfs(s, t)){
        fill(counter.begin(), counter.end(), 0);

        while(int flow = send_flow(s, t, INT_MAX)){
            max_flow += flow;
        }
    }
    return max_flow;

}

int32_t main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin>>a>>b>>w;
        G[a][b] += w;
    }

    cout<<dinic(1, n);
}