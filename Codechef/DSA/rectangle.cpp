#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int> > V[N];
pair<int, int> A[2*N]; 

int main()
{
    int n, x, y;
    cin>>n;
    for(int i=0;i<N;i++) { 
        V[i].push_back(make_pair(500, -1) );
    }

    V[0].push_back(make_pair(0, -1));
    V[100000].push_back(make_pair(0, -1));


    for(int i=1; i<=n; i++){
        cin>>x>>y;
        V[x].push_back(make_pair(y, -1));
    }

    for(int i=0;i<=100000;i++) sort(V[i].begin(), V[i].end());

    int counter=0; 
    for(int i=0; i<=100000; i++){
        for(auto v : V[i]){
            // v = V[0][i], v = V[0][1] ....
            v.second = ++counter;
            A[counter] = {i, v.first}; // {id, x}
        }
    }

    int right_x[N], left_x[N];

    stack<pair<int, pair<int, int> > > S;

    for(int x=0;x<=100000; x++){
        for(auto v: V[x]){
            // y = V[x][0].first, id = V[x][0].second
            // y = V[x][1].first, id = V[x][1].second
            // ...
            // ...
            int y = v.first;
            int id = v.second; 
            while(!S.empty()){
                if(S.top().second.second > y ){
                    right_x[S.top().first] = A[id].first;
                    S.pop();
                } else{
                    break;
                }
            }
            // S.push({id, {x, y}});
            S.push( make_pair(id, make_pair(x, y)) );
        }
    }

    // stack<pair<int, pair<int, int> > > S;
    for(int x=100000; x>=0 ; x++){
            for(auto v: V[x]){
                int y = v.first;
                int id = v.second;
                while(!S.empty()){
                    if(S.top().second.second > y){
                        left_x[S.top().first] = A[id].first;
                        S.pop();
                    } else{
                        break;
                    }
                }
                S.push({id, {x, y}});
            }
        }

    cout<<"check";
    int ans = 0;
    for(int i=0;i<=n;i++){
        for(auto v: V[i]){
            int left = left_x[i];
            int right = right_x[i];
            int height = v.second;
            int width = right - left;
            ans = max(ans, height*width);
        }
    }

    cout<<ans;
}