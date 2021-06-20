#include<bits/stdc++.h>
using namespace std;
#include<vector>

int main()
{
    int nodes,edges,x,y;
    cout<<"Enter number of Nodes and Edges: ";
    cin>>nodes>>edges;

    vector<int> G[nodes+1];
    cout<<"Enter all pair of edges: ";
    for(int i=0;i<edges; i++){
        cin>>x>>y;
        G[x].push_back(y);
    }

    for(int i=0;i<nodes+1;i++){
        for(int j=0;j< G[i].size();j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
}