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

ll mod=1e9+9;
ll p=29;
vll p_pow;


void pow_calc(int siz){
    p_pow.assign(siz+1,1);

    for(int i=1;i<siz;i++) p_pow[i]=(p_pow[i-1]*p)%mod;
}
vll pre_hash,rev_hash;
int siz;
vi dp;

int ret(int id,int l){

    if(dp[l]!=-1) return dp[l];

    if (l==1) return dp[l]=1;

    ll preHash,revHash;

    preHash=(((pre_hash[id+l/2]-pre_hash[id]+mod)%mod)*p_pow[siz-(id+l)])%mod;

    int lbytwo;
    if(l&1) lbytwo=l/2 +1;
    else lbytwo=l/2;

    revHash=(((rev_hash[id+1+lbytwo]-rev_hash[id+l+1]+mod)%mod)*p_pow[id])%mod;

    if(preHash==revHash){
        return dp[l]=(1+ret(id,l/2));
    }
    else return dp[l]=0;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    cin>>input;

    siz=input.size();

    pow_calc(siz);


    pre_hash.assign(siz+1,0),rev_hash.assign(siz+2,0);

    for(int i=1;i<=siz;i++){
        pre_hash[i]=(pre_hash[i-1]+p_pow[i-1]*(input[i-1]-'a'+1))%mod;
    }

    for(int i=siz;i>=1;i--){
        rev_hash[i]=(rev_hash[i+1]+p_pow[siz-i]*(input[i-1]-'a'+1))%mod;
    }

    vi Pal(siz+1,0);
    Pal[1]=siz;
    vi temPal(siz+1,0);
    int maxi=INT_MIN;
    for(int i=0;i<siz;i++){


        dp.assign(siz+1,-1);

        for(int l=2;l<=siz-i;l++){



            int x=ret(i,l);


            temPal[x]++;
            maxi=max(maxi,x);
           // cout<<i<<" "<<x<<' '<<l<<endl;

        }

    }

    for(int i=1;i<=maxi;i++){
        int y=temPal[i];
        for(int j=1;j<=i;j++){
            Pal[j]+=y;
        }
    }

    for(int i=1;i<=siz;i++){
        cout<<Pal[i]<<" ";
    }
    cout<<endl;


    return 0;
}
