#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int d,x,y,z;
        cin>>d>>x>>y>>z;
        int a = 7*x;
        int b = d*y + (7-d)*z;
        cout<<max(a,b)<<endl;
    }
}