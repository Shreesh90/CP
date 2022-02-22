#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        ll ans = 0;
        ll p=0;
        while(1){
            int a = x%10;
            int b = y%10;

            x /= 10;
            y /= 10;

            if(a<=b){
                ans += pow(10,p)*(b-a);
            }
            else if (a>b){
                int ss = y%10;
                if(ss!=1) {
                    ans = -1;
                    break;
                }
                b += 10*ss;
                ans += pow(10,p)*(b-a);
                y /= 10;
            }
            p++;
            if(x!=0 && y==0){
                ans = -1;
                break;
            }
            if(x==0 && y==0) break;
        }
        cout<<ans<<endl;
        
    }
}