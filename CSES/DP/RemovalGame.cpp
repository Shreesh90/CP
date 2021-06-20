#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long static t[5002][5002];

ll solve(vector<ll> &arr, int i, int j){
    if(i>j) return 0;
    if(t[i][j] != -1) return t[i][j];
    ll sum = 0;

    ll x,y,z;
    if(t[i+2][j] != -1){
        x = t[i+2][j];
    } else {
        x = solve(arr, i+2, j);
        t[i+2][j] = x;
    }

    if(t[i+1][j-1] != -1){
        y = t[i+1][j-1];
    } else {
        y = solve(arr, i+1,j-1);
        t[i+1][j-1] = y;
    }

    if(t[i][j-2] != -1){
        z = t[i][j-2];
    } else {
        z = solve(arr ,i, j-2);
        t[i][j-2] = z;
    }

    sum = max(arr[i] + min(x, y), arr[j] + min(y, z));
    return t[i][j] = sum;
}

int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cin>>n;
    vector<ll> a(n);
    for(ll &v: a) cin>>v;

    solve(a, 0, n-1);
    cout<<t[0][n-1];

}