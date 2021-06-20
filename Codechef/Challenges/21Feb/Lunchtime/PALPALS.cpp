#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t; cin>>t;

    while(t--){
        string s; cin>>s;
        map<char, int> mp;
        int even = 0;
        int one = 0;
        for(char c:s){
            mp[c]++;
        }
        for(auto it:mp){
            if(it.second%2 == 0) even += it.second/2;
            else if(it.second%2 == 1){
                if(it.second == 1) one++;
                else even += (it.second-3)/2;
            }
        }

        if(even >= one) cout<<"YES\n";
        else if(even < one) cout<<"NO\n";
        else cout<<"YES\n";
    }
}