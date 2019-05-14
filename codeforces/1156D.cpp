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

vii parent0,parent1;

int Find0(int u){
    if(parent0[u].ff!=u){
        parent0[u].ff=Find0(parent0[u].ff);
    }
    return parent0[u].ff;
}

int Find1(int u){
    if(parent1[u].ff!=u){
        parent1[u].ff=Find1(parent1[u].ff);
    }
    return parent1[u].ff;
}

void Union0(int u,int v){
    int uu=Find0(u),vv=Find0(v);
    if(uu!=vv){
        parent0[uu]=mp(vv,parent0[uu].ss);
        parent0[vv]=mp(vv,parent0[uu].ss+parent0[vv].ss);

    }
}
void Union1(int u,int v){
    int uu=Find1(u),vv=Find1(v);
    if(uu!=vv){
        parent1[uu]=mp(vv,parent1[uu].ss);
        parent1[vv]=mp(vv,parent1[uu].ss+parent1[vv].ss);
    }
}

vvii g;//adjLst;

int main()
{
    //FI;FO;
    FastIO;

    int n; cin>>n;
    g.assign(n+1,vii());

    parent0.resize(n+2),parent1.resize(n+2);
    for(int i=0;i<=n+1;i++) parent0[i]=mp(i,1),parent1[i]=mp(i,1);

    int n1=n-1;
    while(n1--){
        int x,y,c; cin>>x>>y>>c;

        if(c){
            Union1(x,y);
            g[x].pb(mp(y,1));
            g[y].pb(mp(x,1));
        }
        else{
            Union0(x,y);
            g[x].pb(mp(y,0));
            g[y].pb(mp(x,0));
        }
    }

    ll ans=0;

    unordered_map<int,bool> mapp;

    for(int i=1;i<=n;i++){
        int x=Find0(i);
        if(!mapp[x]){
            ll si=parent0[x].ss;
            ans+=si*(si-1);
            mapp[x]=true;
        }
    }

    mapp.clear();
    for(int i=1;i<=n;i++){
        int x=Find1(i);
        if(!mapp[x]){
            ll si=parent1[x].ss;
            ans+=si*(si-1);
            mapp[x]=true;
        }
    }

    for(int i=1;i<=n;i++){
        ll zero=0,one=0;

        ll uu=Find0(i);
        ll vv=Find1(i);

        zero=parent0[uu].ss-1;
        one=parent1[vv].ss-1;

        ans+=zero*one;
    }

    cout<<ans<<endl;

    return 0;
}
