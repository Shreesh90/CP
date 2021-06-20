#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        map<int, int> mp;
        string first;
        int flag=1;
        while(n--){
            string s;
            cin>>s;

            while(flag){
                first = s;
                flag=0;
            }

            if(s == "start" || s == "restart") mp[0]++;
            else mp[1]++;            
        }

        if(mp[0] >= mp[1] && (first=="start" || first == "restart")) cout<<"200"<<endl;
        else cout<<"404"<<endl;
    }
}