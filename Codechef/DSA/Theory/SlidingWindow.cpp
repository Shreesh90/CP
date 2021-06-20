// TIME COMPLEXITY - O(N)
// BRUTE FORCE TIME COMPLEXITY - O(N*K)

#include<bits/stdc++.h>
using namespace std;
// #include<utility>
// #include<deque>

const int N = 1e5 + 5;
int A[N];

deque<pair<int, int> > DQ;

int push(int i){
	while(!DQ.empty()){
		if(DQ.back().first < A[i]){
			DQ.pop_back();
		}
		else{
			break;
		}
	}
	// DQ.push_back({A[i], i});
	DQ.push_back(make_pair(A[i], i) );

}

int query(int l, int r){
	while(!DQ.empty()){
		if(DQ.front().second < l){
			DQ.pop_front();
		}
		else{
			break;
		}
	}
	return DQ.front().first;
}

int main()
{
	int n,k;
	cin>>n>>k;

	for(int i=1; i<=n ;i++) cin>>A[i];

	for(int i=1;i<=k;i++){
		push(i);
	}

	int l=1, r=k;
	cout<<query(l, r)<<" ";
	for(int r=k+1; r<=n ; r++){
		l++;
		push(r);
		cout<<query(l, r)<<" ";
	}

}