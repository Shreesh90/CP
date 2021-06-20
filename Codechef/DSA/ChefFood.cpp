#include<bits/stdc++.h>
using namespace std;
// #define ll long long
const int N=1000;
int profit[N];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		for(int i=1;i<=n;i++){
			int s,p,v;
			cin>>s>>p>>v;

			int num_people = floor( p / (s+1) );
			int prof = num_people * v * 1ll;
			profit[i] = prof;
		}
		int max_profit = *max_element(profit+1, profit+n);
		cout<<max_profit<<"\n";
	}
}


// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int t;
// 	cin>>t;
	
// 	while(t--){
// 		int n;
// 		cin>>n;
//         int profit = 0 ;

// 		for(int i=1;i<=n;i++){
// 			int s,p,v;
// 			cin>>s>>p>>v;

// 			int num_people = floor( p / (s+1) );
// 			int prof = num_people * v;
// 			profit = max(profit, prof);

// 		}
// 		cout<<profit<<"\n";
// 	}
// }