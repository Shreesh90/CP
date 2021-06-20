#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, h, x;
    cin>>n>>h>>x;

    int d = h-x;
    int t[n];
    bool ret = false;
    for(int i=0;i<n;i++){
        cin>>t[i];
        if(t[i] >= d) ret = true;
    }

    if(ret)cout<<"YES\n"; 
    else cout<<"NO\n" ;
}
