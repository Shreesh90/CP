#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        int mini = INT_MAX;
        int maxi = -1;
        
        for(int i=0;i<n;i++) {
            cin>>a[i];
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }

        int ret = 0;
        for(int i=0;i<n;i++){
            if(a[i] == maxi){
                ret += 1;
                continue;
            }
            ret += a[i]/mini;
        }
        cout<<ret<<endl;
    }
}