#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t; cin>>t;
    ll ax,ay,bx,by,cx,cy,dx,dy;
    while(t--){
        ll n, k, x, y;
        cin>>n>>k>>x>>y;
        ll d = y-x;
        ll x0,y0;
        if(d==0 || d==n || d==-n){
            x0 = n;
            y0 = n;
            cout<<x0<<" "<<y0<<endl;
            continue;
        } 
        else if(x==n || y==n){
            x0 = x;
            y0 = y;
            cout<<x0<<" "<<y0<<endl;
            continue;
        }
        else if(d < 0){
            map<int, pair<int,int> > mp;
            mp.insert({1, {n, n-x+y}});
            mp.insert({2, {n-x+y, n}});
            mp.insert({3, {0, x-y}});
            mp.insert({0, {x-y, 0}});
            int temp = k % 4; 
            x0 = mp.at(temp).first;
            y0 = mp.at(temp).second;
            
            cout<<x0<<" "<<y0<<endl;
            continue;
        }
        else if(d > 0){
            map<int, pair<int,int> > mp;
            mp.insert({1, {n-y+x, n}});
            mp.insert({2, {n, n-y+x}});
            mp.insert({3, {y-x, 0}});
            mp.insert({0, {0, y-x}});
            int temp = k % 4; 
            x0 = mp.at(temp).first;
            y0 = mp.at(temp).second;
            
            cout<<x0<<" "<<y0<<endl;
            continue;   
        }
    }
}
