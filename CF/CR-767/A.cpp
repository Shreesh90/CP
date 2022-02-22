#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> A(n),B(n);
		vector<pair<int, int> > v;

		for(int i=0;i<n;i++) cin>>A[i];
		for(int i=0;i<n;i++) cin>>B[i];

		for(int i=0;i<n;i++) {
			v.push_back(make_pair(A[i], B[i]));
		}

		sort(v.begin(), v.end());

		for(int i=0;i<n;i++){
			if(v[i].first <= k){
				k += v[i].second;
			}
		}
		cout<<k<<"\n";
	}
}