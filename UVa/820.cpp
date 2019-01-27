#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>02
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
//#define FIFO
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

#define maxn 105
int V,E,sink,source,maxflow,f;
int res[maxn][maxn];
vi parent;

void augment(int u,int minVal){
    if(u==source) { f=minVal; return;}
    else if(parent[u]!=-1){
        augment(parent[u],min(minVal,res[parent[u]][u]));
        res[parent[u]][u]-=f;res[u][parent[u]]+=f;
    }
}

int main()
{
#ifdef FIFO
    FI;
    FO;
#endif
    FASTIO;

    int cas=1;
    while(cin>>V&&V!=0) {

        mem(res,0);

        cin >> source >> sink>> E;
        source--,sink--;

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--,v--;
            res[u][v] += w;
            res[v][u]+=w;
        }
        maxflow=0;

        while (true) {

            f = 0;
            parent.assign(V, -1);

            queue<int> q;
            q.push(source);
            vi dist(V, INF);
            dist[source] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;

                for (int v = 0; v < V; v++) {
                    if (dist[v] == INF && res[u][v] > 0) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }

            augment(sink, INF);

            if (f == 0) break;

            maxflow += f;
        }

        cout<<"Network "<<cas++<<endl;

        cout << "The bandwidth is "<<maxflow << "."<<endl<<endl;
    }


    return 0;
}
