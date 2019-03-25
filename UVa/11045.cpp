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
#define INF 100000000
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

int res[41][41];
vi parent;
int f,source;

void augment(int u,int minval)
{
    if(u==source){ f=minval;return;}
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

    int t; cin>>t;

    map<string,int> mapp;

    mapp["L"]=1;
    mapp["XL"]=2;mapp["XXL"]=3;
    mapp["S"]=4;mapp["XS"]=5;
    mapp["M"]=6;
    source=0;

    int sink=40;
    while(t--){

        mem(res,0);

        int n,m; cin>>n>>m;

        int sup=n/6;

        for(int i=1;i<=6;i++){
            res[0][i]=sup;
        }

        for(int i=1;i<=m;i++){
            string s1,s2;
            cin>>s1>>s2;

            res[mapp[s1]][6+i]=100000;
            res[mapp[s2]][6+i]=100000;
            res[6+i][40]=1;
        }

        int maxflo=0;

        while(true){

            queue<int> q;
            q.push(source);
            vi dist(41,INT_MAX);
            parent.assign(41,-1);
            dist[source]=0;
            f=0;

            while(!q.empty()){
                int v=q.front();
                q.pop();

                if(v==sink) break;

                for(int i=0;i<41;i++){
                    if(dist[i]==INT_MAX and res[v][i]>0){
                        parent[i]=v;
                        q.push(i);
                        dist[i]=dist[v]+1;
                    }
                }

            }

            augment(sink,INT_MAX);

            if(f==0) break;

            maxflo+=f;

        }

        if(maxflo==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}
