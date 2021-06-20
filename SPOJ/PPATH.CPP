#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> G[100001];
int visited[100001];
int dist[100001];
vector<int> primes;

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x % i == 0)return false;
    }
    return true;
}

bool isValid(int a, int b){
    int count=0;
    while(a > 0 && b > 0){
        if(a%10 != b%10) count++;
        a /= 10; b /= 10;
    }
    // cout<<a<<" "<<b<<" "<<count<<endl;
    if(count == 1) return true;
    return false;
}

void makeGraph(){
    for(int i=1000;i<=9999;i++){
        if(isPrime(i)) primes.pb(i);
    }

    for(int i=0 ; i<primes.size() ; i++){
        for(int j=i+1 ; j<primes.size() ; j++){
            int a = primes[i];
            int b = primes[j];
            if(isValid(a, b)){
                G[a].pb(b);
                G[b].pb(a);
            }
        }
    }
}

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child: G[curr]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
                dist[child] = dist[curr]+1;
            }
        }
    }
}


int main(){
    int t; cin>>t;

    makeGraph();

    while(t--){ 
        int a, b;
        cin>>a>>b;

        for(int i=1000;i<=9999;i++){
            dist[i] = -1;
            visited[i] = 0;
        }

        bfs(a);

        // for(int x: G[a]) cout<<x<<" ";

        if(dist[b] == -1) cout<<"Impossible"<<endl;
        else cout<<dist[b]<<endl;

    }
}
