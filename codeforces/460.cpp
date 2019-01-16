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

    int t; cin>>t;

    for(int i=0;i<t;i++){
        if(i!=0) cout<<endl;

        int xl,yl,xu,yu;
        cin>>xl>>yl>>xu>>yu;
        vii vec;
        vec.pb(pii(xl,yl));
        vec.pb(pii(xu,yu));
        vi yy;
        yy.pb(yl),yy.pb(yu);

        int x1l,y1l,x1u,y1u;
        cin>>x1l>>y1l>>x1u>>y1u;

        yy.pb(y1l),yy.pb(y1u);

        sortv(yy);

        vec.pb(pii(x1l,y1l));
        vec.pb(pii(x1u,y1u));

        if(x1u<=xl||xu<=x1l||y1u<=yl||yu<=y1l){
            cout<<"No Overlap"<<endl;
        }
        else{
            sortv(vec);
            cout<<vec[1].first<<" "<<yy[1]<<" "<<vec[2].first<<" "<<yy[2]<<endl;
        }

    }

    return 0;
}
