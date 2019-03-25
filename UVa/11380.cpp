#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"WTH: "<<x<<endl
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS 1e-12
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define ff first
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)
#define INF 100000
#define ld long double
#define ll long long
#define mem(x,y) memset(x,y,sizeof x)
#define mp make_pair
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x);
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define siz(x) (int)x.size()
#define sortv(v) sort(v.begin(),v.end())
#define ss second
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>

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

int dirx[]={-1,1,0,0};
int diry[]={0,0,1,-1};
int res[1805][1805];
vvi adjLst;
int source,f;
vi parent;

void augment(int u,int minval){
    if(u==source){ f=minval; return;}
    if(parent[u]!=-1){
        augment(parent[u],min(minval,res[parent[u]][u]));
        res[parent[u]][u]-=f;
        res[u][parent[u]]+=f;
    }
}

int main()
{
    //FI;FO;
    FastIO;

    int x,y,p;

    source=0;
    int sink=1802;

    while(cin>>x>>y>>p){

        mem(res,0);
        adjLst.assign(1805,vi());

        string ara[x];
        fof(i,0,x){
            cin>>ara[i];
        }

        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){

                int in,out;

                in=i*30+j+1;
                out=900+in;
                adjLst[in].pb(out);
                adjLst[out].pb(in);

                if(ara[i][j]=='*' or ara[i][j]=='.'){
                    res[in][out]=1;
                    if(ara[i][j]=='*') {
                        res[source][in]=1;
                        adjLst[source].pb(in);
                    }
                }
                else if(ara[i][j]=='#' or ara[i][j]=='@'){
                    res[in][out]=INF;
                    if(ara[i][j]=='#') {
                        res[out][sink]=p;
                        adjLst[out].pb(sink);
                    }
                }

                for(int k=0;k<4;k++){

                    int yy=diry[k]+i;
                    int xx=dirx[k]+j;

                    if(yy>=0 and yy<x and xx>=0 and xx<y){
                        int to=yy*30+xx+1;

                        if(ara[yy][xx]!='~') {
                            res[out][to] = INF;
                            adjLst[out].pb(to);
                            adjLst[to].pb(out);
                        }

                    }

                }



            }
        }

        int maxflo=0;

        while(true){
            f=0;
            parent.assign(1805,-1);
            vi dist(1805,INT_MAX);
            queue<int> q;
            q.push(source);
            dist[source]=0;
            while(!q.empty()){
                int v=q.front();
                q.pop();

                if(v==sink) break;

                for(int i=0;i<siz(adjLst[v]);i++){
                    int to=adjLst[v][i];

                    if(dist[to]==INT_MAX and res[v][to]>0){
                        q.push(to);
                        dist[to]=dist[v]+1;
                        parent[to]=v;
                    }
                }

            }

            augment(sink,INT_MAX);
            if(f==0) break;
            maxflo+=f;
        }

        cout<<maxflo<<endl;

    }

    return 0;
}
