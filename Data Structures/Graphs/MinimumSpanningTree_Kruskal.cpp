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

struct Graph* sort(struct Graph* graph,int E){
    // Bubble Sort
    for(int i=0;i<E;i++){
        for(int j=0;j<E-1;j++){
            int w1 = graph->edge[j].weight;
            int w2 = graph->edge[j+1].weight;
            if(w1>w2){
                struct Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j+1];
                graph->edge[j+1] = temp;
            }
        }
    }
    return graph;
}

struct subset{
    int parent;
    int rank;
};

int find(struct subset* subsets, int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(struct subset* subsets, int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int isCycle(struct Graph* graph, int U, int V, struct subset* subsets){
    int N = graph->N;
    int E = graph->E;

    // struct subset* subsets = (struct subset*)malloc(sizeof(struct subset));

    // for(int i=0;i<V;i++){
    //     subsets[i].parent = i;
    //     subsets[i].rank = 0;
    // }

    // for(int i=0;i<E;i++){
        int x = find(subsets, U);
        int y = find(subsets, V);

        if(x == y)
            return 1;
        
        
    // }
    return 0;
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

    graph = sort(graph, E);

    struct subset* subsets = (struct subset*)malloc(N * sizeof(struct subset));
    for(int i=0;i<N;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    struct Graph* MST = createGraph(N+1,E);
    int visited[N+1] = {0};
    int e=0;
    for(int i=0;i<E;i++){
        int u = graph->edge[i].U;
        int v = graph->edge[i].V;
        
        int x = find(subsets, u); // finding parent of node u in its subset
        int y = find(subsets, v); // finding parent of node v in its subset
        
        
        //!isCycle(MST, u, v, subsets)
        if(x != y){ //If their parents are not same then combining them into one set
            MST->edge[e++] = graph->edge[i];
            Union(subsets, x, y);
        }

        
    }
    
    cout<<endl<<"The Minimum Spanning Tree of the above Graph is: \n";
    for(int j=0;j<e;j++){
        cout<<MST->edge[j].U<<"->"<<MST->edge[j].V<<" : Weight- "<<MST->edge[j].weight;
        cout<<endl;
    }

}