 #include<bits/stdc++.h>
using namespace std;
#include<stack>
#include<vector>

void DFS(int a, int *visited, vector<int> *G){
        // if(visited[a]) return;
        visited[a] = 1;
        cout<<a<<" ";
        for(int i=0; i<G[a].size(); i++){
            if(!visited[G[a][i]]){
                int v = G[a][i];
                DFS(v, visited, G);
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

    // for(int i=0;i<nodes+1;i++){
    //     for(int j=0;j< G[i].size();j++)
    //         cout<<G[i][j]<<" ";
    //     cout<<"\n";
    // }

    //Depth First Search
    int visited[nodes+1] = {0};
    int u = 1;
    DFS(u, visited, G);

}