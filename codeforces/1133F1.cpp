#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
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
void print(vector<T> vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
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

int n,m;
vvi adjLst;
vector<bool>visited;

vvi adj;

void dfs(int u){
    visited[u]=true;
    int siz=adjLst[u].size();
    vi temp;
    fof(i,0,siz){
        int v=adjLst[u][i];
        if(!visited[v]){
            temp.pb(v);
            adj[u].pb(v);
        }
    }

    fof(i,0,siz){
        int v=adjLst[u][i];
        if(!visited[v]){
            visited[v]=true;
        }
    }

    fof(i,0,temp.size()){
        dfs(temp[i]);
    }
}

int main()
{
    //FI;FO;
    FASTIO;


    cin>>n>>m;

    adjLst.assign(n+1,vi());
    adj.assign(n+1,vi());

    int degree[n+1];
    mem(degree,0);
    int idx=1;
    int maxdegree=0;

    fof(i,0,m){
        int u,v;
        cin>>u>>v;
        adjLst[u].pb(v);
        adjLst[v].pb(u);
        degree[u]++;
        degree[v]++;
        if(degree[u]>maxdegree){
            maxdegree=degree[u];
            idx=u;
        }
        if(degree[v]>maxdegree){
            maxdegree=degree[v];
            idx=v;
        }
    }

    visited.assign(n+1,false);

    dfs(idx);

    for(int i=1;i<=n;i++){
        int siz=adj[i].size();

        fof(j,0,siz){
            cout<<i<<" "<<adj[i][j]<<endl;
        }
    }

    return 0;
}
