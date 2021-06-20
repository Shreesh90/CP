#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        string s;
        cin>>s;

        if( sort(s.begin(), s.end()) == "CMP") cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}