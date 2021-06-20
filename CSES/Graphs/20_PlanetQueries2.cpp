#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int maxN = 30;
int LCA[200001][30];
int temp, req;
int ans;

int value(int x){
    int ret = temp;
    for(int j=0;j<maxN;j++){
        if(x & (1<<j)) ret = LCA[ret][j];
    }
    return ret;
}

void bs(int l, int r){
    while(l < r){
        int mid = l + (r-l)/2;
        if(value(mid) == req){
            ans = mid;
            r = r - 2;
            //  return mid;
        }
        if(value(mid) < req) l = mid+1;
        else r = mid-1;
    }

    ans = -1;
    // return -1;

}

int32_t main()
{
    int n, q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        LCA[i][0] = x;
    }

    for(int j=1;j<maxN;j++){
        for(int i=1;i<=n;i++){
                int pa = LCA[i][j-1];
                LCA[i][j] = LCA[pa][j-1];
        }
    }

    while(q--){
        int x, b;
        cin>>x>>b;
        temp = x;
        req = b;
        int counter=0;
        int f=0;
        
        // for(int i=0;i<=n;i++){
        //     temp = x;
            
            // for(int j=0;j<maxN;j++){
            //     if(i & (1<<j)) temp = LCA[temp][j];
            // }
            bs(0, n);
            if(x != b) cout<<ans<<endl;
            else cout<<0<<endl;

            // if(temp == b){
            //     counter = i;
            //     f=1;
            //     break;
            // }
        // }

        // if(f) cout<<counter<<endl;
        // else cout<<-1<<endl;
        
    }
}