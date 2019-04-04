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
#define sfl(x)                      scanf("%I64",&x);
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
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
    for(int i=0;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
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

int dirx[]={1,-1,0,0};
int diry[]={0,0,-1,1};
vvi g;

int main()
{
    //FI;FO;
    FastIO;

    int n,m;
    cin>>n>>m;

    string mat[m];

    fof(i,0,m){
        cin>>mat[i];
    }

    g.assign(m*n,vi());
    int idx=-1;

    fof(i,0,m){
        fof(j,0,n){

            if(mat[i][j]=='.'){

                int u=i*n+j;
                idx=u;
                for(int k=0;k<4;k++){

                    if(i+diry[k]>=0 and i+diry[k]<m and j+dirx[k]>=0 and j+dirx[k]<n){
                        int ii=i+diry[k];
                        int jj=j+dirx[k];

                        if(mat[ii][jj]=='.'){
                            int v=ii*n+jj;
                            g[u].pb(v);
                        }

                    }

                }

            }

        }
    }

    if(idx!=-1){
        int id;

        queue<int> q;
        q.push(idx);

        id=idx;

        vb visited(n*m,false);
        visited[id]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            fof(i,0,siz(g[u])){
                int v=g[u][i];
                if(!visited[v]){
                    visited[v]=true;
                    id=v;
                    q.push(v);
                }
            }
        }

        int layer[n*m];
        mem(layer,-1);
        q.push(id);

        layer[id]=0;
        int lay=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            fof(i,0,siz(g[u])){
                int v=g[u][i];
                if(layer[v]==-1){
                    layer[v]=layer[u]+1;
                    q.push(v);
                    lay=max(lay,layer[v]);
                }
            }
        }

        cout<<lay<<endl;

    }
    else cout<<0<<endl;

    return 0;
}
