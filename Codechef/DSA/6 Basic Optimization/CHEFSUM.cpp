#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t; cin>>t;

    while(t--){
        ll n; cin>>n;
        ll a[n];

        ll minIndex = 1000000;
        ll min = 100000000000;
        ll sum = 0;

        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum += a[i];
        }

        ll cache=100000000000;
        for(ll i=0;i<n;i++){
            ll temp = sum + a[i];
            
            if(temp < min){
                min = temp;
                // minIndex = i;
                if(temp < cache) minIndex = i;
                cache = temp;
            }
            // cache = temp;
        }

        cout<<minIndex+1<<endl;
    }

}