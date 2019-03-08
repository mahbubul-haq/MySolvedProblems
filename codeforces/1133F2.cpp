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
#define vb vector<bool>
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

vvi adjLst;
int n,m,d;
vvi adj;
vb visited,visited1,taken;
bool isPos=true;

void dfs1(int u){
    visited1[u]=true;
    int siz=adjLst[u].size();

    fof(i,0,siz){
        int v=adjLst[u][i];
        if(!visited1[v]&&v!=1){
            dfs1(v);
        }
    }
}

void dfs(int u){
    visited[u]=true;
    int siz=adjLst[u].size();

    vi temp;

    if(u==1) {
        visited1.assign(n+1,false);
        taken.assign(n+1,false);
    }
    for(int i=0;i<siz;i++){
        int v=adjLst[u][i];
        if(u==1){

            if(!visited1[v]){
                temp.pb(v);
                taken[v]=true;
                visited[v]=true;
                adj[u].pb(v);
                dfs1(v);
            }

        }

        else if(!visited[v]){
            temp.pb(v);
            adj[u].pb(v);
            visited[v]=true;
        }
    }

    if(u==1&&temp.size()>d){
        isPos=false;
        return;
    }
    else if(u==1)
    {
        int i=0;
        while(temp.size()!=d){

            if(!visited[adjLst[u][i]]){
                visited[adjLst[u][i]]=true;
                temp.pb(adjLst[u][i]);
                adj[adjLst[u][i]].pb(u);
            }
            i++;
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

    cin>>n>>m>>d;
    adjLst.assign(n+1,vi());
    adj.assign(n+1,vi());
    int degree[n+1];
    mem(degree,0);

    fof(i,0,m){
        int u,v;
        cin>>u>>v;
        adjLst[u].pb(v);
        adjLst[v].pb(u);
        degree[u]++;
        degree[v]++;
    }

    if(degree[1]<d){
        cout<<"NO"<<endl;
    }
    else{
        visited.assign(n+1,false);
        dfs(1);



        if(isPos) {

            cout << "YES" << endl;

            fof(i, 1, n + 1) {
                int siz = adj[i].size();
                fof(j, 0, siz) {
                    cout << i << " " << adj[i][j] << endl;
                }
            }
        }

        else cout<<"NO"<<endl;
    }

    return 0;
}
