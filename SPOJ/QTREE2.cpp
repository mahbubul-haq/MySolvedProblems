#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pib pair<int,bool>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
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

///=======================================template=======================================///
#define maxn 10005
vvii adjLst;
vi parent;
vii level;
int table[maxn][14];
int n;

void dfs(int from,int u,int dep,int dis){
    parent[u]=from;
    level[u]=mp(dep,dis);

    for(int i=0;i<(int)adjLst[u].size();i++){
        pii v=adjLst[u][i];

        if(from!=v.ff){
            dfs(u,v.ff,dep+1,dis+v.ss);
        }
    }
}

void lca_init(){
    mem(table,-1);

    for(int i=0;i<n;i++){
        table[i][0]=parent[i];
    }

    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(table[i][j-1]!=-1){
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
}

int distq(int p,int q){
    if(level[p].ff<level[q].ff) swap(p,q);

    int log=1;

    while((1<<log)<=level[p].ff){
        log++;
    }

    for(int i=log;i>=0;i--){
        if(level[p].ff-(1<<i)>=level[q].ff) p=table[p][i];
    }

    if(p==q) return p;

    for(int i=log;i>=0;i--){
        if(table[p][i]!=-1 and table[p][i]!=table[q][i]){
            p=table[p][i],q=table[q][i];
        }
    }

    return parent[p];
}

int kth(int p,int q,int k){
    int lca=distq(p,q);

    if(level[p].ff-level[lca].ff+1>=k){
        k--;
        int log=1;
        while((1<<log)<=level[p].ff) log++;

        for(int i=log;i>=0;i--){
            if((1<<i)<=k){
                p=table[p][i];
                k-=(1<<i);
            }
        }
        return p;

    }
    else{

        k-=level[p].ff-level[lca].ff+1;
        int temp=level[q].ff-level[lca].ff;

        k=temp-k;

        int log=1;
        while((1<<log)<=level[q].ff) log++;

        for(int i=log;i>=0;i--){
            if((1<<i)<=k){
                q=table[q][i];
                k-=(1<<i);
            }
        }
        return q;

    }

}

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    while(t--){
        cin>>n;

        adjLst.assign(n,vii());
        parent.assign(n,0);
        level.assign(n,mp(0,0));

        fof(i,0,n-1){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            adjLst[u].pb(mp(v,w));
            adjLst[v].pb(mp(u,w));
        }

        dfs(-1,0,0,0);
        lca_init();

        while(true){
            string query; cin>>query;
            if(query=="DONE") break;
            else if(query=="DIST"){
                int u,v;
                cin>>u>>v;
                u--,v--;
                int lca=distq(u,v);

                cout<<(ll)level[u].ss+level[v].ss-2*(ll)level[lca].ss<<endl;

            }
            else{
                int u,v,k;
                cin>>u>>v>>k;
                u--,v--;

                cout<<kth(u,v,k)+1<<endl;
            }
        }
        
        cout<<endl;
    }

    return 0;
}
