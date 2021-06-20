#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main() {
    int n; cin>>n;
    string g[n];
    vector<int> s;
    
    for(int i=0;i<n;i++){
        cin>>g[i];

        if(g[i] == "X"){
            s.pop_back();
        }
        else if(g[i] == "Y"){
            int temp = s[s.size()-1];
            s.pb(2*temp);
        } 
        else if(g[i] == "+"){
            int a = s[s.size()-1];
            int b = s[s.size()-2];
            s.pb(a+b);
        }
        else {
            s.pb(stoi(g[i]));
        }
    }
    ll sum=0;
    for(int x:s){
        sum+=x;
    }
    cout<<sum;

}