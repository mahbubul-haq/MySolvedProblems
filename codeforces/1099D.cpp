#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define MOD 998244353
#define EPS 1e17
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e18
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

///=======================================template=======================================///
ll ans=0;
vll ara;
vvi AdjLst;
int n;

ll dfs(int id,int layer,ll tempsum){

    if(layer&1){

        if(tempsum>ara[id]){
            ans=-INF;
            return 0;
        }

        ans+=(ara[id]-tempsum);

        for(int i=0;i<AdjLst[id].size();i++){

            dfs(AdjLst[id][i],layer+1,ara[id]);
        }
    }
    else{

        int siz=AdjLst[id].size();

        if(siz==0) return 0;

        int temp=AdjLst[id][0];

        ll val=INF;
        for(int i=0;i<siz;i++){
            val=min(ara[AdjLst[id][i]]-tempsum,val);
            if(tempsum>ara[AdjLst[id][i]]) {
                ans=-INF;
                return 0;
            }
        }
        ans+=val;

        for(int i=0;i<siz;i++){
            dfs(AdjLst[id][i],layer+1,tempsum+val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

     cin>>n;


    AdjLst.assign(n+2,vi());

    for(int i=2;i<=n;i++){
        int x; cin>>x;
        AdjLst[x].pb(i);
    }
    ara.assign(n+2,0L);

    for(int i=1;i<=n;i++) cin>>ara[i];

    dfs(1,1,0);

    if(ans<0) cout<<"-1"<<endl;
    else cout<<ans<<endl;


    return 0;
}
