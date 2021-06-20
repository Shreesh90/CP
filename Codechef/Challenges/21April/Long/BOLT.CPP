#include<bits/stdc++.h>
using namespace std;

double rounding(float f){
    double v = (int)(f * 100 + 0.5);
    return (double)v/100.0;
}

int main() {
    setprecision(2);
    int t; cin>>t;
    while(t--){
        double k1,k2,k3,v;
        cin>>k1>>k2>>k3>>v;
        double ans = rounding(100.0 / (v*k1*k2*k3*1.0));
        // cout<<ans<<endl;

        if(ans < 9.58) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}