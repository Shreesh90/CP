#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n, z;
        cin>>n>>z;
        priority_queue<int> powers;
        ll sum=0;
        for(ll i=0;i<n;i++){
            int x;
            cin>>x;
            powers.push(x);
        }
        
        int count = 0;
        int flag=0;
        while(z > 0){
            if(powers.top() == 0){
                cout<<"Evacuate"<<"\n";
                flag = 1;  
                break;
            }
            int largest = powers.top();
            powers.pop();
            z = z - largest;
            count++;
            largest = largest / 2;
            powers.push(largest);
        }
        if(flag == 0) cout<<count<<"\n";
    }
}

