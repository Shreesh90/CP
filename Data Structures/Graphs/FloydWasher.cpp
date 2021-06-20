#include<bits/stdc++.h>
using namespace std;
#define INF 99999

void floydWarshall(int *graph, int nodes){
    
    int dist[nodes][nodes],i,j,k;

    for(i=0;i<nodes;i++)
        for(j=0;j<nodes+1;j++)
            dist[i][j] =*((graph+i*(nodes)) + j); 
    
    for(k=0;k<nodes;k++){
        for(i=0;i<nodes;i++){
            for(j=0;j<nodes;j++){
                if(dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
                cout<<dist[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int main()
{

    // int nodes,edges,weight,x,y;
    // cout<<"Enter number of Nodes and Edges: ";
    // cin>>nodes>>edges;

    // int graph[nodes+1][nodes+1];
    // for(int i=0;i<nodes+1;i++)
    //     for(int j=0;j<nodes+1;j++)
    //         graph[i][j] = INF;

    // cout<<"Enter edges x, y and their weights: ";
    // for(int i=0;i<edges;i++){
    //     cin>>x>>y>>weight;
    //     graph[x][y] = weight;
    // }

    int graph[4][4] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      };

    floydWarshall((int*)graph, 4);
}