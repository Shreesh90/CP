#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int num_cars;
		cin>>num_cars;

		int speeds[num_cars];
		int max_speed = 0;
		int counter = 0;
		for(int i=0;i<num_cars;i++){
			cin>>speeds[i];
			if(max_speed == 0){
				max_speed=speeds[i];
			}
			if(speeds[i] <= max_speed){
				max_speed = speeds[i];
				counter++;
			}

		}
		cout<<counter<<"\n";
	}
}