 #include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t; cin>>t;
	while(t--){
		ll l,r,k;
		cin>>l>>r>>k;

		if(l==r){
			if(l == 1) cout<<"NO\n";
			else cout<<"YES\n";
		}
		else {
			ll n = r-l+1;
			ll odd;
			if(l%2==0){
				odd = (r-l+1)/2;
			}
			else {
				odd = (r-l+2)/2;
			}
			ll minop = odd;
			if(k>=minop) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}