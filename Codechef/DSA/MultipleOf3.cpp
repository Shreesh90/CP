#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll k;
        int d0,d1;
        cin>>k>>d0>>d1;

        int s = d0+d1;
        int cycle = (2*s)%10 + (4*s)%10 + (8*s)%10 + (6*s)%10;

        ll num_cycles = (k-3)/4;
        ll total = 0;

        if(k==2){
            total = s;
        }
        else{
            total = s + s%10 + (num_cycles * cycle * 1ll);
            int leftover = k - 3 - (num_cycles*4);
            int num = 2;
            for(int i=0;i<leftover;i++){
                total += (num*s)%10;
                num = num*2; 
            }
        }

        if(total % 3 == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}