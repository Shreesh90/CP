#include<bits/stdc++.h>
using namespace std;
#include<string>

int main()
{
	int t;
	cin>>t;
	while(t--){
		int num_activities;
		string origin;
		cin>>num_activities>>origin;

		int laddus=0;
		int temp_laddus=0;
		while(num_activities--){
			string activity;
			int value;
			cin>>activity;
			if(activity == "CONTEST_WON"){
				cin>>value;
				if(value<=20)
					temp_laddus = 300 + (20-value);
				else
					temp_laddus = 300;
			}

			if(activity == "TOP_CONTRIBUTOR")
				temp_laddus = 300;
			if(activity == "BUG_FOUND"){
				cin>>value;
				temp_laddus = value;
			}
			if(activity == "CONTEST_HOSTED")
				temp_laddus = 50;

			laddus += temp_laddus;
		}

		if(origin == "INDIAN")
			cout<<laddus/200<<"\n";
		else
			cout<<laddus/400<<"\n";
	}
}