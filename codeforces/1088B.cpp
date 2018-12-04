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
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define debugx(x) cout<<"WTH! "<<x<<endl
#define debug(x,y) cout<<x<<" "<<y<<endl

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

    int n,k;
    cin>>n>>k;

    ll a[n+3];

    ff(i,1,n) cin>>a[i];

    sort(a+1,a+n+1);

   // ff(i,1,n) cout<<a[i]<<" ";

    int cnt=n;

    int idx=1;
    ll minus=0;
    bool flag=true;
    for(int i=0;i<k;i++){


        while(flag&&(a[idx]-minus)==0){
            idx++;
            if(idx==n+1) flag=false;
        }

        if(!flag) cout<<0<<endl;
        else {
            int x;
            (0> (a[idx]-minus))? x=0:x=a[idx]-minus;
            cout<<x<<endl;
        }
        minus=a[idx];

    }


    return 0;
}
