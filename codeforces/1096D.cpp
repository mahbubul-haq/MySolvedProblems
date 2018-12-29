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

int n;
string s;
vll ara;

ll dp[100001][6];

ll ret(int id,int cntrl){
    if(id>=n){
        if(cntrl<4) return 0;
        else return 1e16;
    }

    if(dp[id][cntrl]!=-1) return dp[id][cntrl];

    ll temp=1e16;

    if(cntrl==0&&s[id]=='h'){
        temp=min(ret(id+1,cntrl+1),temp);
        temp=min(ara[id]+ret(id+1,cntrl),temp);
    }
    else if(cntrl==1&&s[id]=='a'){
        temp=min(ret(id+1,cntrl+1),temp);
        temp=min(ara[id]+ret(id+1,cntrl),temp);
    }
    else if(cntrl==2&&s[id]=='r'){
        temp=min(ret(id+1,cntrl+1),temp);
        temp=min(ara[id]+ret(id+1,cntrl),temp);
    }
    else if(cntrl==3&&s[id]=='d'){
        temp=min(ret(id+1,cntrl+1),temp);
        temp=min(ara[id]+ret(id+1,cntrl),temp);
    }
    else if(cntrl==4){
        return dp[id][cntrl]=temp;
    }
    else temp=min(temp,ret(id+1,cntrl));

    return dp[id][cntrl]=temp;


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>s;
    ara.resize(n);
    mem(dp,-1);
    for(int i=0;i<n;i++) cin>>ara[i];

    cout<<ret(0,0)<<endl;

    return 0;
}
