
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>02
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define PI acos(-1.0)

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

///=======================================template=======================================///

ll bigmod(ll a,ll b){
    a%=MOD;
    ll res=1;

    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x; cin>>x;

    ll fnum=1,dnum=1;

    int ara[130];

    for(int i=1;i<=x;i++) cin>>ara[i];

    sort(ara+1,ara+x+1);

   fnum=ara[x];

    for(int i=1;i<=x;i++){
        if(i==x){
            if(fnum%ara[i]==0) continue;
            else dnum=(dnum*ara[i])/gcd(dnum,ara[i]);
        }
        if(ara[i]==ara[i+1]){
            fnum=(fnum*ara[i])/gcd(fnum,ara[i]);
            dnum=(dnum*ara[i])/gcd(dnum,ara[i]);
            i++;
        }
        else{
            if(fnum%ara[i]==0) continue;
            else dnum=(dnum*ara[i])/gcd(dnum,ara[i]);
        }
    }

    cout<<fnum<<" "<<dnum<<endl;

    return 0;
}
