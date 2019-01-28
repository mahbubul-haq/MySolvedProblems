#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
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
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
//#define FIFO
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

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

#define maxn 205
int res[maxn][maxn];
int mf,f,source,sink;
vi parent;

void augment(int u,int minVal){
    if(u==source){ f=minVal; return;}
    else if(parent[u]!=-1){
        augment(parent[u],min(minVal,res[parent[u]][u]));
        res[parent[u]][u]-=f;
        res[u][parent[u]]+=f;
    }
}


int main()
{
#ifdef FIFO
    FI;
    FO;
#endif
    FASTIO;
    
    int T; cin>>T;

    for(int cas=1;cas<=T;cas++){

        int n; cin>>n;
        mem(res,0);

        for(int i=1;i<=n;i++){
            int c; cin>>c;
            res[2*i-1][2*i]+=c;
        }
        int m; cin>>m;

        for(int i=0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            res[u*2][v*2-1]+=c;
        }

        int b,d;
        cin>>b>>d;

        for(int i=0;i<b;i++){
            int v; cin>>v;
            res[0][v*2-1]=INF;
        }
        for(int i=0;i<d;i++){
            int u; cin>>u;
            res[u*2][201]=INF;
        }

        source=0,sink=201;

        mf=0;
        while(true){

            queue<int> q; q.push(source);
            vi dist(202,INF);
            parent.assign(202,-1);
            dist[source]=0;
            f=0;

            while(!q.empty()){
                int u=q.front(); q.pop();

                if(u==sink) break;

                for(int v=0;v<=201;v++){
                    if(dist[v]==INF&&res[u][v]>0){
                        dist[v]=dist[u]+1;
                        q.push(v);
                        parent[v]=u;
                    }
                }
            }

            augment(sink,INF);
            if(f==0) break;
            mf+=f;

        }

        cout<<"Case "<<cas<<": "<<mf<<endl;


    }


    return 0;
}
