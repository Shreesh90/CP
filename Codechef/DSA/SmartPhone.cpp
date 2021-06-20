#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;

    long long int bud[n];

    for(int i=0;i<n;i++){
        cin>>bud[i];
    }

    sort(bud, bud+n);
    long long int max = -100;
    long long int value;
    for(int i=0;i<n;i++){
        long long int temp = bud[i];
        value = temp*(n-i);
        if(max < value) max = value;
    }

    cout<< max; 
}