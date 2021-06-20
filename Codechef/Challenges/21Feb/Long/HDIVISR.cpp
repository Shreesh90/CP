#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int max = 1;
    for(int i=2;i<=10;i++){
        if(n%i == 0) max = i;
    }
    cout<<max<<endl;
}

