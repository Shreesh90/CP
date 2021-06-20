#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
ll int S[N];
ll int minS[N];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1 ; i<=n ; i++){
			cin>>S[i];
			minS[i] = S[i];
		}
		ll sum = 0;
		for(int i=2; i<=n ; i++){
			if(minS[i] > minS[i-1] ){
				minS[i] = minS[i-1];
			}
		}
		
		for(int i=1;i<=n;i++){
			sum += minS[i];
		}
		cout<<sum<<"\n";
	}

	return 0;
}