#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges, x, y;
    cout<<"Number of Nodes and edges: ";
    cin>>nodes>>edges;

    int G[nodes+1][nodes+1];
    for(int i=0; i<nodes+1; i++)
        for(int j=0; j<nodes+1; j++)
            G[i][j] = 0;   

    cout<<"Enter the edge pair list:  ";
    for(int i=0; i<edges; i++){
        cin>>x>>y;
        G[x][y] = 1;
    }

    cout<<"\n";
    for(int i=0; i<nodes+1; i++){
        for(int j=0; j<nodes+1; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
         

}