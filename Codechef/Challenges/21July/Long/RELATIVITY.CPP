#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int g,c;
        cin>>g>>c;

        long long h = pow(c,2)/(2*g);
        cout<<(int)h<<endl;

    }
}