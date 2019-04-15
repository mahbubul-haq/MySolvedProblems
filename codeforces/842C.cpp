#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         100000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vpll                        vector<pll>

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
template<class T> void print(vector<T> &vec){
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================//

vvi g;//adjLst;
vi parent,a;
vi ans;
vii divs;
int n;



void dfs(int u,int gcd,int dep){

    vii temp;

    if(siz(g[u])>2 and u!=1) temp=divs;
    else if(siz(g[u])>1 and u==1) temp=divs;

    for(auto v:g[u]){

        if(v!=parent[u]) {
            parent[v]=u;

            int gc=__gcd(gcd,a[v]);

            fob(i,siz(divs)-1,0){
                if(a[v]%divs[i].ff==0){
                    divs[i].ss++;
                }
            }

            for(int i=siz(divs)-1;i>=0;i--){
                if(gc>=divs[i].ff){
                    //fap(mp(v,gc));

                    ans[v]=gc;
                    break;
                }
                else if(divs[i].ss>=dep){
                    ans[v]=divs[i].ff;
                    //fap(mp(v,divs[i]));
                    //fap(1);
                    break;
                }
            }

            dfs(v,gc,dep+1);
            divs=temp;
        }
    }
}

int main()
{
    //FI;FO;
    FastIO;

    int n; cin>>n;

    parent.resize(n+1),a.resize(n+1),ans.resize(n+1);
    g.resize(n+1);

    fof(i,1,n+1) cin>>a[i];

    fof(i,1,n){
        int x,y; cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    parent[1]=-1;
    ans[1]=a[1];
    int sqr=sqrt(a[1])+1;



    for(int i=1;i<=sqr;i++){
        int ii=a[1]/i;
        if(ii*i==a[1] and i<ii){
            divs.pb(mp(ii,0));
            divs.pb(mp(i,0));
        }
        else if(ii*i==a[1] and ii==i) divs.pb(mp(i,0));
    }

    sortv(divs);
    //print(divs);

    dfs(1,0,0);

    print(ans);

    return 0;
}
