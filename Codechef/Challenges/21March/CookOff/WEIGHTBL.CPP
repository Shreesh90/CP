#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int w1,w2,x1,x2,m;
        cin>>w1>>w2>>x1>>x2>>m;
        int minx = m*x1;
        int maxx = m*x2;
        int inc = w2-w1;
        if(inc < minx || inc >maxx) cout<<0<<endl;
        else cout<<1<<endl;

    }
}