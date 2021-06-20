#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t; cin>>t;

    while(t--){
        ll n, m, k;
        cin>>n>>m>>k;
        double a[n+1][m+1], aux[n+1][m+1];
        
        memset(aux, 0, sizeof(aux));
        memset(a, 0, sizeof(a));

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }

        // Creating auxilary matrix
        
        // for(ll i=1;i<=m;i++){
        //     aux[1][i] = a[1][i];
        // }

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                aux[i][j] = a[i][j] + aux[i-1][j];
            }
        }

        for(ll i=1;i<=n;i++){
            for(ll j=2;j<=m;j++){
                aux[i][j] += aux[i][j-1];
            }
        }

        ll mini = min(n, m);
        ll count = 0;

        for(ll x=1;x<=mini;x++){
            for(ll i=x;i<=n;i++){
                for(ll j=x;j<=m;j++){
                    // double avg = (aux[i][j] - aux[i-x][j] - aux[i][j-x] + aux[i-x][j-x]) / (x*x);
                    if( (aux[i][j] - aux[i-x][j] - aux[i][j-x] + aux[i-x][j-x]) / (x*x) >= k){
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
