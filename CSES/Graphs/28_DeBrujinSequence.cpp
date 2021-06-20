#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int 
int n;
// We us unordered set in order to reduce the time complexity else we get TLE
unordered_set<string> seen;
vector<int> edges;

void dfs(string starting, string &A){
    
    for(int i=0;i<2;i++){
        string str = starting + A[i];
        if(seen.find(str) == seen.end()){
            // cout<<str<<" ";
            seen.insert(str);
            dfs(str.substr(1), A);
            edges.pb(i);
        }
    }

}

int32_t main()
{
    cin>>n;
    string A = "01";
    string startingNode = string(n-1, A[0]);
    dfs(startingNode, A);

    string ret = "";

    int l = pow(2, n);
    for(int i=0;i<l;i++){
        ret += A[edges[i]];
    }

    ret += startingNode;


    // for(string s: seen) cout<<s<<" ";
    // cout<<endl;
    // for(int x: edges) cout<<x<<" ";
    // cout<<endl;
    cout<<ret;
}