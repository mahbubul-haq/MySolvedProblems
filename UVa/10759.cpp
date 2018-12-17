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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int n,x;
unsigned long long dp[25][152];
unsigned long long ret(int id,int val){
    if(id==n+1){
        if(val>=x) return 1;
        else return 0;
    }

    if(dp[id][val]!=-1) return dp[id][val];
    unsigned long long val1=0;
    for(int i=1;i<=6;i++){
        val1+=ret(id+1,val+i);
    }

    return dp[id][val]=val1;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin>>n>>x&&!(n==0&&x==0)){
        mem(dp,-1);
        unsigned long long denom=1;
        for(int i=1;i<=n;i++) denom*=6;
        unsigned long long numer=ret(1,0);

        unsigned long long GCD=gcd(denom,numer);

        if((numer/GCD)%(denom/GCD)==0){
            cout<<(numer/GCD)/(denom/GCD)<<endl;
        }
        else {
            cout << numer / GCD << "/"<<denom/GCD<<endl;
        }

    }

    return 0;
}
