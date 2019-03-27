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
#define msi map<string,int>
#define mii map<int,int>
#define mis map<int,string>
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x)
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
    fof(i,0,vec.size()) cout<<vec[i].ss<<" "; cout<<endl;
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

int res[205][205];
vi parent;
int source=0,sink=204,f;

void augment(int u,int minval){
    if(u==source) { f=minval; return;}
    else if(parent[u]!=-1){
        augment(parent[u],min(minval,res[parent[u]][u]));
        res[parent[u]][u]-=f;
        res[u][parent[u]]+=f;
    }
}

int main()
{
    //FI;FO;
    //FastIO;

    int t;
    sfi(t);

    fof(cas,1,t+1){
        cout<<"Case "<<cas<<":"<<endl;
        mem(res,0);

        int m,n;
        cin>>m>>n;

        int l[205],r[205];
        //parent.assign(105,-1);

        int minus=0;
        fof(i,1,n+m) {
            cin>>l[i];
            if(i<=n and i<=m) minus++;
            else if(i<=n or i<=m) minus=minus;
            else minus--;
            res[0][i]=l[i]-minus;
        }

        minus=0;
        fof(i,1,n+m){
            cin>>r[i];
            if(i<=n and i<=m) minus++;
            else if(i<=n or i<=m) minus=minus;
            else minus--;
            res[i+n+m][sink]=r[i]-minus;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                int ii,jj;

                ii=i-1+j;
                jj=i-1+n-j+1+n+m;
                res[ii][jj]=99;
                //if(j!=n) cout<<" ";

            }
           // cout<<endl;
        }
        /*for(int i=0;i<n+m;i++){
            for(int j=1;j<n+m;j++){
                cout<<res[i][j]<< " ";
            }
            cout<<res[i][sink]<<endl;
        }*/

        int maxflo=0;
        while(true){
            f=0;
            parent.assign(205,-1);
            vi dist(205,INT_MAX);

            queue<int> q;
            dist[source]=0;
            q.push(source);

            while(!q.empty()){
                int v=q.front();
                q.pop();

                if(v==sink) break;
                //debug(1);

                for(int i=1;i<205;i++){
                    if(dist[i]==INT_MAX and res[v][i]>0){
                        dist[i]=dist[v]+1;
                        q.push(i);
                        parent[i]=v;
                    }
                }
            }
            augment(sink,INT_MAX);

            if(f==0) break;
            maxflo+=f;
            //cout<<maxflo<<endl;

        }

        //cout<<maxflo<<endl;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                int ii,jj;

                ii=i-1+j;
                jj=i-1+n-j+1+n+m;

                cout<<99-res[ii][jj]+1;
                if(j!=n) cout<<" ";

            }
            cout<<endl;
        }

    }

    return 0;
}
