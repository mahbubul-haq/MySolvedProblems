#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
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

string input;

//pll mod={1e9+9,1e9+7};
//pll p={257,263};

ll mod=1e9+9;
ll p=257;

//vector<pll> pre_hash,rev_hash;
//vector<pll> p_pow;
vector< ll > pre_hash,rev_hash;
vector< ll > p_pow;

void pow_calc(int siz){
    p_pow.assign(siz,1);

    for(int i=1;i<siz;i++) {
        p_pow[i]=(p_pow[i-1]*p)%mod;
    }
}

vi isPal;
int siz;

int  isKPal(int id){
   // id++;

    if(id==1) return isPal[id]=1;

    if(isPal[id]!=-1) return  isPal[id];

    ll phash,revhash;

    phash=pre_hash[id/2];
    int x=id/2;
    revhash=((rev_hash[id+1-id/2]-rev_hash[id+1]+mod)%mod);
    phash=(phash*p_pow[siz-id])%mod;

    int val=0;

    if(revhash==phash){
        val=1+isKPal(id/2);
    }
    else val=0;
    return isPal[id]=val;


}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>input;

    ll ans=0;

    siz=input.size();
    pow_calc(siz);
    isPal.assign(siz+1,-1);

    ///pre_hash

    pre_hash.assign(siz+1,0);
    pre_hash[0]=0;

    for(int i=1;i<=siz;i++){
        pre_hash[i]=(pre_hash[i-1]+(p_pow[i-1]*input[i-1]))%mod;
    }
    ///rev_hash

    rev_hash.assign(siz+2,0);
    rev_hash[siz+1]=0;

    for(int i=siz;i>=1;i--){
        rev_hash[i]=(rev_hash[i+1]+p_pow[siz-i]*input[i-1])%mod;
    }


    for(int i=0;i<siz;i++){

       ans+=isKPal(i+1);

    }

    cout<<ans<<endl;

    return 0;
}
