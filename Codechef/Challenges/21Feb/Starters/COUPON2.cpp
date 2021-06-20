#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int d, c;
        cin>>d>>c;

        int a[3], b[3];
        int sum1=0, sum2=0;
        int count=0;
        for(int i=0;i<3;i++) {
            cin>>a[i];
            sum1 += a[i];    
        }
        for(int i=0;i<3;i++) {
            cin>>b[i];
            sum2 += b[i];
        }
        if(sum1 < 150) count++;
        if(sum2 < 150) count++;
    
        int cost_without_coupon = sum1 + sum2 + d + d;
        int cost_with_coupon = sum1 + sum2 + c + (count*d);

        if(cost_with_coupon < cost_without_coupon) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

