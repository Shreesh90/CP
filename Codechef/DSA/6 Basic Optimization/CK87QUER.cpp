#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t; cin>>t;

    while(t--){
        ll n; cin>>n;

        ll pairs = 0;
        for(int i=1;i<=700;i++){
            ll temp = n-i;
            if(temp <= 0) break;
            ll p = floor(sqrt(temp));
            pairs += p;
        }

        cout<<pairs<<endl;
    }
}
