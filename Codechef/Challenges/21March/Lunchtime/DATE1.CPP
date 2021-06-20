#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int t; cin>>t;
    while(t--){
        ll a,y,x;
        cin>>a>>y>>x;
        if(a >= y) cout<<y*x<<endl;
        else cout<<(a*x + 1)<<endl;
    }
}