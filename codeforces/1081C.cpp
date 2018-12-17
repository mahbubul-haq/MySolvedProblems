#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 998244353
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

int k;
int n,m;

ll bigmod(ll a,ll b){
    if(b==0) return 1;
    ll x=bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b&1) x=(a*x)%MOD;
    return x;
}

ll dp[2005][2000];

ll ret(int id,ll cnt){
    if(id==n+1){
        if(cnt==k) return 1;
        else return 0;
    }

    if(dp[id][cnt]!=-1) return dp[id][cnt];

    ll val1,val2;

    val1=ret(id+1,cnt);
    val2=ret(id+1,cnt+1);

    return dp[id][cnt]=(val1+val2)%MOD;

}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

         cin>>n>>m>>k;
    mem(dp,-1);

        if(k==0){
            cout<<m<<endl;
            return 0;
        }

        if(m==1){
            cout<<0<<endl;
            return 0;
        }
        if(n==1){
            cout<<m<<endl;
            return 0;
        }

        ll ans=0;
        ans=ret(2,0);

    ///cout<<ans<<endl;

   // cout<<bigmod(m-1,k)<<endl;

        ans=(ans*bigmod(m-1,k))%MOD;
     ans=(ans*m)%MOD;
        cout<<ans<<endl;


        return 0;
}
