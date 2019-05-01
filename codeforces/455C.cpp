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

vvi g;//adjLst
int n,m,q;
vi longest;
vi parent,temp;
vb visited;

int Find(int u){
    if(parent[u]!=u) parent[u]=Find(parent[u]);
    return  parent[u];
}

void Union(int u,int v){
    int uu=Find(u),vv=Find(v);
    if(uu!=vv){
        parent[uu]=vv;
        longest[vv]=max(longest[vv],max((longest[uu]+1)/2+(longest[vv]+1)/2+1,longest[uu]));
    }
}

int maxl=-1,vtx;

umii mapp;
void dfs(int u,int layer){
    mapp[u]=1;
    visited[u]=true;
    temp.pb(u);
    if(maxl<layer){
        maxl=layer;
        vtx=u;
    }
    for(auto v: g[u]) {
        if(!visited[v]) dfs(v,layer+1);
    }
}


void dfs1(int u,int layer){
    mapp[u]=0;

    if(maxl<layer){
        maxl=layer;
    }

    for(auto v: g[u]){
        if(mapp[v]) dfs1(v,layer+1);
    }

}

int main()
{
    //FI;FO;
    FastIO;

    cin>>n>>m>>q;
    g.resize(n+1);
    longest.assign(n+1,0);
    parent.assign(n+1,0);
    visited.assign(n+1,false);

    for(int i=1;i<=n;i++) parent[i]=i;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        temp.clear();
        if(!visited[i]){
            maxl=-1,vtx=i; mapp.clear();
            dfs(i,0);
            maxl=-1;
            dfs1(vtx,0);
            parent[temp[0]]=temp[0];
            for(int j=1;j<siz(temp);j++){
                parent[temp[j]]=parent[temp[0]];
            }
            longest[temp[0]]=maxl;
        }

    }

    while(q--){
        int t; cin>>t;
        //print(longest);
        if(t==1){
            int x; cin>>x;
            x=Find(x);
            //cout<<x<<endl;
            cout<<longest[x]<<endl;
        }
        else {
            int u,v; cin>>u>>v;
            Union(u,v);
        }
    }

    return 0;
}
