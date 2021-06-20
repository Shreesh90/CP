#include<bits/stdc++.h>
using namespace std;
#include<stack>
#include<vector>

bool DFS(int a,int check, int *visited, vector<int> *G,int balloons){
        if(visited[a]) return true;
        visited[a] = 1;
        
        for(int i=0; i<G[a].size(); i++){
            int v = G[a][i];
            DFS(v,check, visited, G,balloons);
        }

        int sum=0;
        for(int i=0; i<balloons;i++)
            sum += visited[i];
        if(sum == balloons && a==check){return true;}
        else if(sum != 0 && a==check){return false;}
}

int main()
{
    // Adjacency List
    int balloons,number,x,y;
    cout<<"Enter total number of Balloons: ";
    cin>>balloons;
    
    vector<int> G[balloons];
    
    for(int i=0;i<balloons;i++){
        cout<<"Number of values in Balloon "<<i<<": ";
        cin>>number;
        cout<<"Enter values in balloon "<<i<<": ";
        for(int j=0; j<number;j++){
            cin>>x;
            G[i].push_back(x);
        }
    }
    //Depth First Search
    bool value[balloons];
    for(int i=0;i<balloons;i++){
        int visited[balloons] = {0};
        value[i] = DFS(i,i,visited, G,balloons);
    }

    int ans = false;
    for(int i=0;i<balloons;i++){
        ans |= value[i];
    }
    
    if(ans == true) cout<<"True";
    else cout<<"False";

}