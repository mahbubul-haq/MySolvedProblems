#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define siz(x) (int)x.size()
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
    fof(i,0,vec.size()) cout<<vec[i].ff<<" "; cout<<endl;
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

vvi adjLst;
vi parent,level;
int n;

int table[5005][13];

void dfs(int from,int u,int dep){
    parent[u]=from;
    level[u]=dep;

    for(int i=0;i<siz(adjLst[u]);i++){
        int v=adjLst[u][i];

        if(v!=from){
            dfs(u,v,dep+1);
        }
    }
}

void init_lca(){
    mem(table,-1);
    for(int i=0;i<n;i++) table[i][0]=parent[i];

    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(table[i][j-1]!=-1){
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
}

int lca(int p, int q){
    if(level[p]<level[q]) swap(p,q);

    int log=1;

    while((1<<log)<=level[p]) log++;

    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]) p=table[p][i];
    }

    if(p==q) return q;

    for(int i=log;i>=0;i--){
        if(table[p][i]!=-1 and table[p][i]!=table[q][i]){
            p=table[p][i];
            q=table[q][i];
        }
    }

    return parent[p];
}

int kth(int p,int k){

    int log=1;
    while((1<<log)<=level[p]) log++;

    for(int i=log;i>=0;i--){

        if((1<<i)<=k){
            p=table[p][i];
            k-=(1<<i);
        }

    }
    return p;

}

pii query(int p,int q){
    int lcas=lca(p,q);

    int dis1=level[p]-level[lcas];
    int dis2=level[q]-level[lcas];

    if((dis1+dis2)&1){
        int dis=(dis1+dis2)/2;
        if(level[p]<level[q]) swap(p,q);

        int kt=kth(p,dis);

        return mp(kt,parent[kt]);
    }
    else{

        int dis=(dis1+dis2)/2;

        if(level[p]<level[q]) swap(p,q);

        int kt=kth(p,dis);
        return mp(-1,kt);
    }
}

int main()
{
    //FI;FO;
    FastIO;

    while(cin>>n and n!=0){
        adjLst.assign(n,vi());
        parent.assign(n,0);
        level.assign(n,0);

        fof(i,0,n-1){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adjLst[u].pb(v);
            adjLst[v].pb(u);
        }

        dfs(-1,0,0);
        init_lca();

        int q; cin>>q;

        while(q--){
            int u,v;
            cin>>u>>v;
            u--,v--;
            pii ans=query(u,v);

            if(ans.ff==-1){
                cout<<"The fleas meet at "<<ans.ss+1<<"."<<endl;
            }
            else{
                cout<<"The fleas jump forever between "<<min(ans.ff+1,ans.ss+1)<<" and "<<max(ans.ff+1,ans.ss+1)<<"."<<endl;
            }
        }

    }

    return 0;
}
