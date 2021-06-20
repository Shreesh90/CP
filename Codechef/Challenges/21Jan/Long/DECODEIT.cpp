#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t; cin>>t;
    map<string, char> mp;
    mp.insert({"0000", 'a'});
    mp.insert({"0001", 'b'});
    mp.insert({"0010", 'c'});
    mp.insert({"0011", 'd'});
    mp.insert({"0100", 'e'});
    mp.insert({"0101", 'f'});
    mp.insert({"0110", 'g'});
    mp.insert({"0111", 'h'});
    mp.insert({"1000", 'i'});
    mp.insert({"1001", 'j'});
    mp.insert({"1010", 'k'});
    mp.insert({"1011", 'l'});
    mp.insert({"1100", 'm'});
    mp.insert({"1101", 'n'});
    mp.insert({"1110", 'o'});
    mp.insert({"1111", 'p'});

    while(t--){
        ll n; cin>>n;
        string s; cin>>s;
        string ans = "";
        string temp;
        for(int i=0;i<s.length();i+=4){
            if(i<n) {temp = s.substr(i, 4);
            ans += mp[temp];}
        }
       cout<<ans<<endl;
    }
}
