#include<bits/stdc++.h>
using namespace std;
#include<queue>
#include<vector>

void BFS(vector<int> *G, int nodes){
    int visited[nodes+1] = {0};
    queue<int> Q;
    Q.push(1); // 1 --> Node to start BFS from 
    visited[1] = 1;

    while(!Q.empty()){
        int u = Q.front();
        cout<<u;
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(visited[v] == 0){
                Q.push(v);
                visited[v] = 1;
            }
        }
    }

}

int main()
{
    // Adjacency List
    int nodes,edges,x,y;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>nodes>>edges;

    vector<int> G[nodes+1];
    cout<<"Enter all pair of edges: ";
    for(int i=0;i<2*edges; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    for(int i=0;i<nodes+1;i++){
        for(int j=0;j<G[i].size();j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }

    //Breadth First Search
    BFS(G, nodes);
}