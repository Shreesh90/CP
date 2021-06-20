#include<bits/stdc++.h>
using namespace std;
#define INF_ -99999

int maxKey(int *key, int *visited, int nodes){
    int max = INF_ , max_index;
    for(int i=0;i<nodes+1;i++){
        if(key[i] > max && visited[i] == 0){
            max = key[i];
            max_index = i;
        }
    }
    return max_index;
}

int min(int weight, int key){
    return (weight<key)?weight:key ;
}


void WidestDistance(int *graph, int src, int dest, int nodes){
    int visited[nodes+1] = {0};
    int key[nodes+1];

    for(int i=0;i<nodes+1;i++)
        key[i] = INF_ ;
    key[src] = -INF_;

    bool condition = true;
    cout<<"Widest path in the Graph between "<<src<<" and "<<dest<<" is: ";
    for(int i=0;i<nodes+1;i++){
        int u = maxKey(key,visited,nodes);
        visited[u] = 1;
        if(u == dest){
            cout<<u;
            condition = false;
        }
        if(condition)
            cout<<u<<"-";

        for(int v=0;v<nodes+1;v++){
            // *(graph + u*(nodes+1) + v)   //*(graph + u*(nodes+1) + v)+key[u]
            if( *(graph + u*(nodes+1) + v) != 0 &&  min( *(graph + u*(nodes+1) + v) , key[u] ) > key[v] && visited[v] == 0)
                key[v] = min( *(graph + u*(nodes+1) + v) , key[u] ) ;
        }
    }
    cout<<"\nWidest Distance between "<<src<<" and "<<dest<<" is: "<<key[dest];
    
}

int main()
{
    int nodes,edges,x,y,weight,src,dest;
    cout<<"Enter number of nodes and edges: ";
    cin>>nodes>>edges;
    int graph[nodes+1][nodes+1];
    for(int i=0;i<nodes+1;i++)
        for(int j=0;j<nodes+1;j++)
            graph[i][j] = 0;
        
    
    cout<<"Enter nodes x,y and their weights: ";
    for(int i=0;i<edges;i++){
        cin>>x>>y>>weight;
        graph[x][y] = weight;

    }
    cout<<"Enter Source and Target node to find Maximum distance between them: ";
    cin>>src>>dest;
    WidestDistance(*graph, src, dest, nodes);
}