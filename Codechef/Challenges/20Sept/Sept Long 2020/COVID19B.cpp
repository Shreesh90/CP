#include<bits/stdc++.h>
using namespace std;

int n;
int v[10], d[10];

void search(int l, int r){

}

int main()
{
    int t; cin>>t;

    while(t--){
         cin>>n;

         for(int i=0;i<n;i++){ 
            cin>>v[i];
            d[i] = i;
         }

         search(0, 10000);

    }
}