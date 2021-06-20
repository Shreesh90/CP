#include<bits/stdc++.h>
using namespace std;
#include<stack>
#include<vector>

void DFS(int a,int check, int *visited, vector<int> *G,int nodes){
        if(visited[a]) return;
        visited[a] = 1;
        // cout<<a<<" ";
        for(int i=0; i<G[a].size(); i++){
            int v = G[a][i];
            DFS(v,check, visited, G,nodes);
        }

        int sum=0;
        for(int i=0; i<nodes;i++)
            sum += visited[i];
        if(sum == nodes && a==check) cout<<a<<" ";
}

int main()
{
    // Adjacency List
    int nodes,edges,x,y;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>nodes>>edges;

    vector<int> G[nodes+1];
    cout<<"Enter all pair of edges: ";
    for(int i=0;i<edges; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    //Depth First Search
    for(int i=0;i<nodes;i++){
        int visited[nodes] = {0};
        DFS(i,i,visited, G,nodes);
    }

}