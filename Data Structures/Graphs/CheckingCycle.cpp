#include<bits/stdc++.h>
using namespace std;

struct edge{
    int U;
    int V;
};

struct Graph{
    int V,E;
    struct edge* edges;
};

struct subset{
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct edge*)malloc(E * sizeof(struct edge));
    return graph;
}

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

int isCycle(struct Graph* graph){
    int V = graph->V;
    int E = graph->E;

    struct subset* subsets = (struct subset*)malloc(sizeof(struct subset));

    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for(int i=0;i<E;i++){
        int x = find(subsets, graph->edges[i].U);
        int y = find(subsets, graph->edges[i].V);

        if(x == y)
            return 1;
        Union(subsets, x, y);
        
    }
    return 0;
}

int main()
{
    int V=3,E=3;
    struct Graph* graph = createGraph(V, E);

    graph->edges[0].U = 0;
    graph->edges[0].V = 1;

    graph->edges[1].U = 1;
    graph->edges[1].V = 2;

    graph->edges[2].U = 0;
    graph->edges[2].V = 2;

    if(isCycle(graph))
        cout<<"Graph is Cyclic.";
    else
        cout<<"Graph id Acyclic";
    
}



