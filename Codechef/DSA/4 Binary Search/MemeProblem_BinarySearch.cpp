// Find a and b for a particular x such that (a+b = x) & (a*b = x)

#include<iostream>
using namespace std;
#include<cstdlib>

int main()
{
    int t;
    cin>>t;

    while(t--){
        long double x;
        cin>>x;

        long double lo = 0;
        long double hi = x/2.0;

        while(lo <= hi){
            long double mid = (hi + lo)/2;
            long double num = (mid)*(x-mid);

            long double delta1 = abs(mid + (x-mid) - num);
            long double delta2 = abs(mid + (x-mid) - x);

            if(delta1 <= 1e-6 && delta2 < 1e-6){
                cout<<"Y"<<" "<<mid <<" "<<x-mid<<endl;
                break;
            }

            else if(num < x){
                lo = mid+1.0;
            }
            else if(num > x){
                hi = mid-1.0;
            }
            else{
                cout<<"N"<<endl;
                break;
            }
        }
    }
}