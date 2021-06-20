#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int l,b;
        cin>>l>>b;
        cout<<gcd(l,b) <<endl;
    }
}