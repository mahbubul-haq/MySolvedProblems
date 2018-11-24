#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define MAX 4e18
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};
int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    ff(i,1,t){
        ll cntb=0,cntw=0;
        ll n,m;
        cin>>n>>m;

        if(n*m%2==0) {
            cntw=(n*m)/2;
            cntb=cntw;
        }
        else{
            cntb=(n*m)/2;
            cntw=cntb+1;
        }

        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;


        if((x1+y1)%2==0){
            ll val=(x2-x1+1)*(y2-y1+1);

            if(val%2==0){
                cntb-=val/2;
                cntw+=val/2;
            }
            else{
                cntb-=(val/2);
                cntw+=(val/2);
            }

        }
        else{
            ll val=(x2-x1+1)*(y2-y1+1);

            if(val%2==0){
                cntb-=val/2;
                cntw+=val/2;
            }
            else{
                cntb-=(val/2+1);
                cntw+=(val/2+1);
            }
        }

        ll x3,y3,x4,y4;
        cin>>x3>>y3>>x4>>y4;


        if((x3+y3)%2==0){
            ll val=(x4-x3+1)*(y4-y3+1);

            if(val%2==0){
                cntb+=val/2;
                cntw-=val/2;
            }
            else{
                cntb+=(val/2+1);
                cntw-=(val/2+1);
            }

        }
        else{
            ll val=(x4-x3+1)*(y4-y3+1);

            if(val%2==0){
                cntb+=val/2;
                cntw-=val/2;
            }
            else{
                cntb+=(val/2);
                cntw-=(val/2);
            }
        }

        ll maxx=min(x4,x2),minx=max(x1,x3);


        ll maxy=min(y4,y2),miny=max(y1,y3);

        if(miny>maxy||minx>maxx){
            cout<<cntw<<" "<<cntb<<endl;
            continue;
        }
        else{

            if((minx+miny)%2==0){
                ll val=(maxx-minx+1)*(maxy-miny+1);

                if(val%2==0){
                    cntb+=val/2;
                    cntw-=val/2;
                }
                else{
                    cntb+=(val/2);
                    cntw-=val/2;
                }
            }

            else{

                ll val=(maxx-minx+1)*(maxy-miny+1);

                if(val%2==0){
                    cntb+=val/2;
                    cntw-=val/2;
                }
                else{
                    cntb+=(val/2+1);
                    cntw-=(val/2+1);
                }

            }

            cout<<cntw<<" "<<cntb<<endl;

        }

    }

    return 0;
}
