#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

vector<int> v;
int f(int x){
    return v[x];
}
int ub(int k ,int lo, int hi){
    int return_x = INF;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int fmid = f(mid);

        if(fmid > k){
            return_x = min(mid, return_x);
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return return_x;
}

signed main()
{
    int t;
    cin>>t;

    while(t--){
        v.clear();
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        
        for(int i=0;i<n;i++){
            int index = ub(a[i], 0,  v.size()-1);
            if(index == INF){
                index = v.size();
                v.push_back(a[i]);
            }
            else v[index] = a[i];
        }
        
        cout<<v.size()<<" ";
        for(auto j: v) cout<<j<<" ";
        cout<<endl;
    }

}

