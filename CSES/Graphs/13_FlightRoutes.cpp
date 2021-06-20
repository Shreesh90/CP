#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define int long long int

vector<pii> G[100001];
int processed[100001];

int32_t main()
{
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        G[x].pb({y, w});
    }
    
    vector<vector<int> > dist(n+1, vector<int> (k, 9e15));

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(processed , 0, sizeof(processed));
    pq.push({0, 1});
    dist[1][0] = 0;
    
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        // Here we cannot use processed array since we need to find many shortest paths instead of only the least shortest path
        // processed[curr] = 1;

        if(dist[curr][k-1] < curr_d) continue;

        for(auto c: G[curr]){
            // if(processed[c.first]) continue; 

            int d = curr_d + c.second;

            if(d < dist[c.first][k-1]){
                dist[c.first][k-1] = d;
                pq.push({dist[c.first][k-1], c.first});
                sort(dist[c.first].begin(), dist[c.first].end());
            }
        }
    }

    for(auto v: dist){
        for(int x: v) cout<<x<<"\t";
        cout<<endl;
    }

    // for(int i=0;i<k;i++){
    //     cout<<dist[n][i]<<" ";
    // }

}