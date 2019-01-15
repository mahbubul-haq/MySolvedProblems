#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double pi=acos(-1.0);
    int n;
    while(cin>>n&&n!=0){
        int idx=1;
        double maxi=-1e15;

        for(int i=1;i<=n;i++){
            double w,h;
            cin>>w>>h;

            double ah=max(h,w);
            double aw=min(h,w);

            ah=ah/4;

            ah=min(ah,aw);

            aw=aw/2;

            ah=max(aw,ah);

            if(ah-maxi>EPS){
                maxi=ah;
                idx=i;
            }

        }

        cout<<idx<<endl;


    }


    return 0;
}
