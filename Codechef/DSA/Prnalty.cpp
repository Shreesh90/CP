#include<iostream>
using namespace std;
#include<string>

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int left_A=n, left_B=n;
		int score_A=0, score_B=0;

		for(int i=0; i<2*n ; i++){
			if(i%2 == 0){
				score_A += s[i] - '0' ;
				left_A--;
			} else {
				score_B += s[i] - '0';
				left_B--;
			}
			if(score_A > score_B + left_B){
				cout<<i+1<<"\n";
				break;
			}
			else if(score_B > score_A + left_A){
				cout<<i+1<<"\n";
				break;
			}
			else if(score_A==score_B && left_A==0 && left_B==0){
				cout<<i+1<<"\n";
				break;
			}
		}
	}

	return 0;
}