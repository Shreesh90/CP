#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#include<string>

vector<int> time(string s, string t){
    vector<int> v;
    int h,m;
    h = (s[0] - '0')*10 + (s[1] - '0');
    m = (s[3] - '0')*10 + (s[4] - '0');
    v.pb(h);
    v.pb(m);
    if(t == "PM" && v[0] != 12)  v[0] += 12;
    if(t == "AM" && v[0] == 12)  v[0] = 0;
    // cout<<v[0]<<" "<<v[1]<<endl;
    return v;
}

string compare(vector<int> &p, vector<int> &l, vector<int> &r){
    string ret;
    if( 
        p[1] >= l[1] && p[1] <= r[1] &&
        p[0] >= l[0] && p[0] < r[0] ) {
            ret = "1";       
    }
    else ret = "0";
    return ret;
}

int main()
{
    int t; cin>>t;
    while(t--){
       string P,d0;
       cin>>P>>d0;
       vector<int> p0 = time(P, d0);

       int n; cin>>n;
       string l, r, dl, dr;
       vector<int> l0, r0;
        string ans = "";
       for(int i=0;i<n;i++){
           cin>>l>>dl>>r>>dr;
            l0 = time(l, dl);
            r0 = time(r, dr);
            ans += compare(p0,l0,r0);
       }
         cout<<ans<<endl;
    }
}
