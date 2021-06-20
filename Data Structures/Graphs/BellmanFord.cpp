#include<bits/stdc++.h>
using namespace std;
#define INF 99999

struct Edge{
    int U,V,weight;
};

struct Graph{
    int N,E;
    struct Edge* edge;
};

struct Graph* createGraph(int N, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->N = N;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph *graph,int z){
    int N = graph->N;
    int E = graph->E;

    int dist[N];
    for(int i=0; i<N; i++)
        dist[i] = INF;
    dist[z] = 0;

    for(int i=0;i<N-1;i++){
        for(int j=0;j<E;j++){
            int U = graph->edge[j].U;
            int V = graph->edge[j].V;
            int weight = graph->edge[j].weight;
            if(dist[U]!=INF && dist[V] > dist[U] + weight)
                dist[V] = dist[U] + weight;
        }
    }
    for(int i=0;i<E;i++){
        int U = graph->edge[i].U;
        int V = graph->edge[i].V;
        int weight = graph->edge[i].weight;
        if(dist[U]!=INF && dist[V] > dist[U] + weight){
            cout<<"Negative Cycle Exists";
            return;
        }   
    }

    for(int i=0; i<N; i++)
        cout<<dist[i]<<" ";
}

int main()
{
    int N,E,x,y,weight,z;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>N>>E;

    struct Graph* graph = createGraph(N,E);

    cout<<"Enter edges x,y and their Weights: ";
    for(int i=0;i<E;i++){
        cin>>x>>y>>weight;
        graph->edge[i].U = x;
        graph->edge[i].V = y;
        graph->edge[i].weight = weight;        
    }

    cout<<"Enter node to find shortest distance from: ";
    cin>>z;

    BellmanFord(graph, z);

}







