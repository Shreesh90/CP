#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, k;
    cin>>n>>k;
    
    // if( k > 2*n ) {
    //     cout<<-1; 
    //     return 0;
    // }

    list<ll> v;
    vector<ll> r;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        v.push_back(x);
    }
    int temp = k-1;
    while(!v.empty() && temp>0){
        int x = v.front();
        r.push_back(x);
        v.pop_front();
        temp--;
    }

    int max = *max_element(r.begin() ,r.end());
    cout<<max;
    return 0;
}

