#include<bits/stdc++.h>
using namespace std;
#define INF 99999

int minKey(int *key, int *mstSet, int nodes){
    int min = 100000;
    int min_index;

    for(int i=0; i<nodes+1; i++){
        if(key[i] < min && mstSet[i] == 0){
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMST(int *parent, int *graph, int nodes){
    cout<<"The MST is: \n";
    for(int i=1;i<nodes+1;i++){
        cout<<parent[i]<<"->"<<i<<" : Weight-"<< *(graph + parent[i]*(nodes+1) + i) <<endl;
    }
} 

void mstPrims(int *graph, int nodes, int z){
    int parent[nodes+1];
    int key[nodes+1];
    int mstSet[nodes+1];

    for(int i=0;i<nodes+1;i++){
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[z] = 0;
    parent[z] = -1;

    for(int i=0; i<nodes+1; i++){
        int u = minKey(key, mstSet, nodes);
        mstSet[u] = 1;

        for(int v=0;v<nodes+1;v++){
            
            if(*(graph + u*(nodes+1) + v) && mstSet[v] == 0 && *(graph + u*(nodes+1) + v) < key[v]){
                key[v] = *(graph + u*(nodes+1) + v);
                parent[v] = u; 
            }
        }
    }

    printMST(parent, graph, nodes);
}

int main()
{   
    int nodes,edges,x,y,weight,z;
    cout<<"Enter number of nodes and edges: ";
    // cin>>nodes>>edges;
    // int graph[nodes+1][nodes+1] = {0};

    // cout<<"Enter nodes x,y and their weights: ";
    // for(int i=0;i<edges;i++){
    //     cin>>x>>y>>weight;
    //     graph[x][y] = weight;
    //     graph[y][x] = weight;

    // }
    int graph[5][5] = { { 0, 10, 12, 19, 0},  
                        { 10, 0, 7, 0, 4},  
                        { 12, 7, 0, 11, 21},  
                        { 19, 0, 11, 0, 3},  
                        { 0, 4, 21, 3, 0} };  

    cout<<"Enter node to make Minimum Spanning Tree from: ";
    // cin>>z;
    mstPrims((int*)graph, 5, 0);
}