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

#define K 25

class SparseTable{
    vector<vll> st;
    vi log;
public:
    SparseTable(vi ara){
        int n=ara.size();
        log.resize(n+5);
        log[1]=0;
        for(int i=2;i<=n;i++){
            log[i]=log[i/2]+1;
        }

        st.resize(n+5);

        fof(i,0,n){
            st[i].resize(K);
            st[i][0]=ara[i];
        }

        fof(j,1,K+1){
            for(int i=0;i+(1<<j)<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }

    ll rmq(int L,int R){
        int j=log[R-L+1];
        return min(st[L][j],st[R-(1<<j)+1][j]);
    }

};

vvi adjLst;
int dirx[]={-1,1,0,0};
int diry[]={0,0,-1,1};
vector<bool> visited,visited1;
int r2,c2;

void dfs(int u){
    visited[u]=true;
    int siz=adjLst[u].size();

    for(int i=0;i<siz;i++){
        int v=adjLst[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    //FI;FO;
    FASTIO;

    int n; cin>>n;

    int r1,c1; cin>>r1>>c1;
    cin>>r2>>c2;

    string ara[n+1];

    ll cost=1e18;
    adjLst.assign(n*52+1,vi());

    fof(i,1,n+1){
        string input; cin>>input;
        ara[i]=input;
    }

    fof(i,1,n+1){
        fof(j,0,n){

            if(ara[i][j]=='0'){
                fof(k,0,4){
                    if(i+diry[k]>=1&&i+diry[k]<=n&&
                    j+dirx[k]>=0 and j+dirx[k]<n){
                        if(ara[i+diry[k]][j+dirx[k]]=='0'){
                            adjLst[i*50+(j)].pb((i+diry[k])*50+j+dirx[k]);
                            adjLst[(i+diry[k])*50+j+dirx[k]].pb((i)*50+(j));
                        }
                    }
                }
            }

        }
    }

    bool isPos=false;

    visited.assign(n*52+1,false);

    dfs((r1)*50+c1-1);
    visited1=visited;
    visited.assign(n*52+1,false);
    dfs((r2)*50+c2-1);

    vi ans1,ans2;

    fof(i,0,visited.size()){
        if(visited[i]) ans1.pb(i);
    }
    fof(i,0,visited1.size()){
        if(visited1[i]) ans2.pb(i);
    }

    fof(i,0,ans1.size()){
        ll fromx,fromy;
        fromx=(ans1[i]/50);
        fromy=ans1[i]%50+1;
        fof(j,0,ans2.size()){
            int tox,toy;
            tox=ans2[j]/50;
            toy=ans2[j]%50+1;

            cost=min(cost,(fromx-tox)*(fromx-tox)+(fromy-toy)*(fromy-toy));
        }
    }

    cout<<cost<<endl;

    return 0;
}
