#include<bits/stdc++.h>
using namespace std;

int main(){
 	int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        map<char, int> mp;
        for(char c:s) mp[c]++;

        string ret;
        for(auto it: mp){
            while(it.second--) ret += it.first;
        }
        cout<<ret<<endl;
    }
}