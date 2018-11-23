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

    int a,b,c;
    int x1,x2,y1,y2;
    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;

    double dupa=a,dupb=b,dupc=c,dupx1=x1,dupx2=x2,dupy1=y1,dupy2=y2;

    double dist=MAX;

    double dis=abs(dupx1-dupx2)+abs(dupy1-dupy2);
    dist=min(dist,dis);
   

    if(a!=0){

        dupx1=(-dupc-dupb*y1)/dupa;

        dupx2=(-dupc-dupb*y2)/dupa;

        dis=sqrt((dupx1-dupx2)*(dupx1-dupx2)+(dupy1-dupy2)*(dupy1-dupy2))+abs((double)x1-dupx1)+abs((double)x2-dupx2);
        dist=min(dis,dist);

        if(b!=0){
            dupy2=(-dupc-dupa*x2)/dupb;
            dupx2=x2;
            dis=sqrt((dupx1-dupx2)*(dupx1-dupx2)+(dupy1-dupy2)*(dupy1-dupy2))+abs((double)x1-dupx1)+abs(dupy2-(double)y2);
            dist=min(dis,dist);
        }


    }

    if(b!=0){

        dupx1=x1,dupx2=x2,dupy1=y1,dupy2=y2;
        dupy1=(-dupc-dupa*x1)/dupb;

        dupy2=(-dupc-dupa*x2)/dupb;

        dis=sqrt((dupx1-dupx2)*(dupx1-dupx2)+(dupy1-dupy2)*(dupy1-dupy2))+abs(y1-dupy1)+abs((double)y2-dupy2);
        dist=min(dis,dist);

        if(b!=0){
            //dupx1=x1,dupx2=x2,dupy1=y1,dupy2=y2;
            dupy2=y2;
            dupx2=(-dupc-dupb*y2)/dupa;
            dis=sqrt((dupx1-dupx2)*(dupx1-dupx2)+(dupy1-dupy2)*(dupy1-dupy2))+abs((double)y1-dupy1)+abs(dupx2-(double)x2);
            dist=min(dis,dist);
        }


    }

    cout<<fixed<<setprecision(10)<<dist<<endl;

    return 0;
}
