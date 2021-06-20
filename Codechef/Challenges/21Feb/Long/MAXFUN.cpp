#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        ll a[n];
        // vector<int> ar;

        for(int i=0;i<n;i++){
            // int x; cin>>x;
            // ar.push_back(x);
            cin>>a[i];
        }

        sort(a, a + n);
        ll x = a[0];
        ll y = a[n-1];

        ll retu = 2*(y-x);
        cout<<retu<<endl;
    }
}

