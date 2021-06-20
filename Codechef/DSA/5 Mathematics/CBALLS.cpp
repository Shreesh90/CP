#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main()
{
    int t; cin>>t;

    while(t--){

        ll n; cin>>n;
        ll a[n];
        
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        
        int flag=0;
        int init = a[0];
        int g = a[0];
        for(int i=1; i<n;i++){
            g = gcd(g, a[i]);
            if(a[i] >= init) flag=1;
        }

        ll balls=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]%2==1 && g==1 && flag==1){
                    a[i]++;
                    balls++;
                } 
                // else if(a[i]%2==1 && g!=1 && flag==1
                // )
                else {
                    continue;
                }
            }
            else{
                if(a[i]%2==1){
                    if(a[i] >= a[i-1] && g==1){
                        a[i]++;
                        balls++;
                    }
                    else if(a[i] >= a[i-1] && g!=1){
                        continue;
                    } 
                    else {
                        ll temp = a[i];
                        a[i] = a[i-1];
                        balls += a[i] - temp;
                    }
                
                } else {
                    if(a[i] < a[i-1]){
                        ll temp = a[i];
                        a[i] = a[i-1];
                        balls += a[i]-temp;
                    } else {
                        continue;
                    }
                }
            }

        }
        cout<<balls<<endl;
    }
}