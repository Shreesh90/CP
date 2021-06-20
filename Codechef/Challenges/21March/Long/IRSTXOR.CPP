#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int bits = 0;
        ll t = n;
        while(t != 0){
            bits++;
            t >>= 1;
        }
        ll a = pow(2, bits-1) -1;
        ll b = n^a;

        cout<<a*b<<endl;
    }
}