#include<bits/stdc++.h>
using namespace std;
#define INF 99999

int minKey(int *key, int *visited, int nodes){
    int min = 100000, min_index;
    for(int i=0;i<nodes;i++)
        if(key[i] < min && visited[i] == 0){
            min = key[i];
            min_index = i;
        }
    return min_index;
}

void printKey(int *key, int nodes){
    for(int i=0;i<nodes;i++){
        cout<<key[i]<<" ";
    }
    
}

void dijkstra(int graph[9][9], int z, int nodes){
    int visited[nodes] = {0};
    
    int key[nodes];
    for(int i=0;i <nodes;i++)
        key[i] = INF;
    key[z] = 0;

    for(int i=0;i<nodes;i++){
        int u = minKey(key,visited,nodes);
        visited[u] = 1;

        for(int v=0;v<nodes;v++){
            if(graph[u][v] != 0 && graph[u][v]+key[u] < key[v] && visited[v] ==0)
                key[v] = graph[u][v] + key[u];
        }
    }
    printKey(key, nodes);
    
}

int main()
{
    // int nodes,edges,x,y,weight,z;
    // cout<<"Enter number of nodes and edges: ";
    // cin>>nodes>>edges;
    // int graph[nodes+1][nodes+1] = {0};

    // cout<<"Enter noddes x,y and their weights: ";
    // for(int i=0;i<edges;i++){
    //     cin>>x>>y>>weight;
    //     graph[x][y] = weight;
    //     graph[y][x] = weight;

    // }
    // cout<<"Enter node to make Minimum Spanning Tree from: ";
    // cin>>z;

    int graph[9][9] = { { 0, 0, 10, 0, 10},
    {0,0,0,7,5},
    {70,0,0,8,5},
    {0,7,8,0,3},
    {10,5,5,3,0} }; 
    
    // int graph[5][5] = {{1,1,1,1,1},
    //                    {1,1,1,1,1},
    //                    {1,1,1,1,1},
    //                    {1,1,1,1,1},
    //                    {1,1,1,1,1}};
    
    dijkstra(graph, 0, 9);
}