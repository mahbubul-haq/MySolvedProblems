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

vvii adjLst;
vector<pair<int,pii> > elst;
vi level,parent;
vii parent1;
int n;

pii table[50005][16];

int find_parent(int u){
    return parent[u]=(parent[u]==u)? u: find_parent(parent[u]);
}

void dfs(int from,int u,int dep,int cost){
    parent1[u].ff=from;
    parent1[u].ss=cost;
    level[u]=dep;

    fof(i,0,siz(adjLst[u])){
        pii v=adjLst[u][i];

        if(v.ff!=from){
            dfs(u,v.ff,dep+1,v.ss);
        }
    }
}

void init_lca(){
    for(int i=0;i<50005;i++){
        fof(j,0,16) table[i][j]=mp(-1,0);
    }

    fof(i,0,n){
        table[i][0]=parent1[i];
    }
    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(table[i][j-1].ff!=-1){
                table[i][j].ff=table[table[i][j-1].ff][j-1].ff;
                table[i][j].ss=max(table[i][j-1].ss,table[table[i][j-1].ff][j-1].ss);
            }
        }
    }
}

int query(int p,int q){

    int maxi=0;

    if(level[p]<level[q]) swap(p,q);

    int log=1;

    while((1<<log)<=level[p]) log++;

    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
            maxi=max(maxi,table[p][i].ss);
            p=table[p][i].ff;
        }
    }

    if(p==q) return maxi;

    for(int i=log;i>=0;i--){
        if(table[p][i].ff!=-1 and table[p][i].ff!=table[q][i].ff){

            maxi=max(maxi,table[p][i].ss);
            maxi=max(maxi,table[q][i].ss);

            p=table[p][i].ff;
            q=table[q][i].ff;
        }
    }

    return max(maxi,max(parent1[p].ss,parent1[q].ss));

}


int main()
{
    //FI;FO;
    //FastIO;

    int t; scanf("%d",&t);

    fof(cas,1,t+1){
        int m;

        //cin>>n>>m;
        scanf("%d%d",&n,&m);

        adjLst.assign(n,vii());
        elst.clear();

        fof(i,0,m){
            int u,v,c;
            //in>>u>>v>>c;
            scanf("%d%d%d",&u,&v,&c);
            u--,v--;
            elst.pb(mp(c,mp(u,v)));
        }
        parent.resize(n);
        level.resize(n);
        parent1.resize(n);

        fof(i,0,n) parent[i]=i;
        sortv(elst);
        int cnt=0;
        //debug(2);

        for(int i=0;i<siz(elst) and cnt<n-1;i++){

            pair<int,pii> uu=elst[i];

            int u=uu.ss.ff;
            int v=uu.ss.ss;
            int c=uu.ff;

            int pu=find_parent(u);
            int pv=find_parent(v);

            if(pu!=pv){

                parent[pv]=pu;

                adjLst[u].pb(pii(v,c));
                adjLst[v].pb(pii(u,c));
                cnt++;
            }

        }

       /// debug(1);

        dfs(-1,0,0,0);
        init_lca();

        int q;
        ///cin>>q;
        scanf("%d",&q);
        //cout<<"Case "<<cas<<":"<<endl;
        printf("Case %d:\n",cas);

        while(q--){
            int u,v;
            //cin>>u>>v;
            scanf("%d%d",&u,&v);
            u--,v--;
            printf("%d\n",query(u,v));
        }

    }

    return 0;
}
