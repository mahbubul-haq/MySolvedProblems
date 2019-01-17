#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define sortv(v) sort(v.begin(),v.end())

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l,w,h,theta;

    while(cin>>l>>w>>h>>theta){
        double pi=acos(-1.0);
        double ang=pi*theta/180;
        double area;

        if(l*sin(ang)<=h*cos(ang)){

            area=l*h-0.5*l*l*tan(ang);
        }
        else{
            ang=pi/2-ang;
            area=0.5*h*h*tan(ang);
        }
        cout<<fixed<<setprecision(3)<<area*w<<" "<<"mL"<<endl;

    }

    return 0;
}
