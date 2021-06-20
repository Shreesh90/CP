#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int freq[10] = {0};

	for(int i=0;i<n;i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	int sum[4] = {0};
	sum[1] = freq[1] + freq[2];
	sum[2] = freq[2] + freq[3];
	sum[3] = freq[3] + freq[1];

	int min = 1000000;

	for(int i=1;i<=3;i++){
		if(min > sum[i])
			min = sum[i];
	}
	cout<<min<<"\n";

}