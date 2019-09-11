#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF              1000000000000000000
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
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos); }
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos)); }

///=======================================template=======================================///


class data {
public:
    bool flag;
    int totalw;
    vvii dis;
    vector<pair<int, pii > > nodes;
    map<int, pii> map1;
    umii level;
    vi weight;

    data() {
        flag = false;
        totalw = 0;
    }

};

umii mapp;
vvii g;
vb vis;
int cnt, cntt;
vector<data> vec;
bool flg;

void dfs(int u, int parent, int w, int weight, int lev) {
    vis[u] = true;
    mapp[u] = cnt;
    vec[cnt].map1[u] = {cntt++, weight};
    vec[cnt].nodes.pb({u, {parent, w}});
    vec[cnt].weight.pb(weight);
    vec[cnt].level[cntt - 1] = lev;
    vec[cnt].totalw += w;

    for (auto v : g[u]) {
        if(v.ff == parent)
            continue;

        if (vis[v.ff] and mapp[v.ff] == cnt and flg) {
            vec[cnt].flag = true;
            vec[cnt].totalw += v.ss;
            flg = false;
        }
        if (!vis[v.ff]) {
            dfs(v.ff, u, v.ss, weight + v.ss, lev + 1);
        }
    }
}

void init(int cn) {
    int sz = siz(vec[cn].nodes);
    int log = 1;
    while ((1 << log) <= sz)
        log++;
    vec[cn].dis.resize(sz + 5);

    for (int i = 0; i < sz + 5; i++) {
        vec[cn].dis[i].resize(log + 4, {-1, 0});
    }

    for (int i = 0; i < sz; i++) {
        vec[cn].dis[i][0] = {(vec[cn].nodes[i].ss.ff == -1 ? -1 : vec[cn].map1[vec[cn].nodes[i].ss.ff].ff), vec[cn].nodes[i].ss.ss};
    }

    for (int j = 1; j < log; j++) {
        for (int i = 0; i < sz; i++) {
            if (vec[cn].dis[i][j - 1].ff != -1) {
                vec[cn].dis[i][j].ff = vec[cn].dis[vec[cn].dis[i][j - 1].ff][j - 1].ff;
                vec[cn].dis[j][j].ss = vec[cn].dis[vec[cn].dis[i][j - 1].ff][j - 1].ss + vec[cn].dis[i][j - 1].ss;
            }
        }
    }

}

ll dist(int ma, int u, int v) {
    int uu = u, vv = v;
    u = vec[ma].map1[u].ff, v = vec[ma].map1[v].ff;

    int levu = vec[ma].level[u];
    int levv = vec[ma].level[v];
    //cout << levu << " " << levv << endl;

    if (levu < levv)
        swap(u, v);
    int log = 1;
    while ((1 << log) <= vec[ma].level[u]) {
        log++;
    }


    for (int i = log; i >= 0; i--) {
        if (vec[ma].level[u] - (1 << i) >= vec[ma].level[v]) {
            //cout << vec[ma].level[u] << endl;
            u = vec[ma].dis[u][i].ff;
           // cout << u << endl;
        }
    }

    //fap("passed") ;

    int lis;
    if(u == v) {
        lis = u;
    }
    else {
        for (int i = log; i >= 0; i--) {
            if(vec[ma].dis[u][i].ff != -1 and vec[ma].dis[u][i].ff != vec[ma].dis[v][i].ff) {
                u = vec[ma].dis[u][i].ff;
                v = vec[ma].dis[v][i].ff;
            }
        }
        lis = vec[ma].map1[vec[ma].nodes[u].ss.ff].ff;
    }

    //cout << lis << endl;

    int weight1 = vec[ma].weight[lis];
    int wieght2 = vec[ma].weight[vec[ma].map1[uu].ff];
    int wieght3 = vec[ma].weight[vec[ma].map1[vv].ff];

    int dis = wieght2 + wieght3 - 2 * weight1;
    if (vec[ma].flag) {
        //fap(uu);
        //cout << dis << " " << vec[ma].totalw << endl;
        dis = min(dis, vec[ma].totalw - dis);
    }
    return dis;
}

int main() {
    //FI;//FO;
    FastIO;//timeInit;

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":" << endl;
        int n, e;
        cin >> n >> e;
        g.assign(n, vii());
        mapp.clear();

        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;

            g[u].pb({v, w});
            g[v].pb({u, w});
        }

        vis.assign(n, false);
        vec.clear();

        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cntt = 0;
                vec.emplace_back();
                flg = true;

                dfs(i, -1, 0, 0, 0);
                cnt++;
            }
        }

        for (int i = 0; i < siz(vec); i++) {
            init(i);
        }

        int q;
        cin >> q;
        while (q-- > 0) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (mapp[u] == mapp[v]) {
                cout << dist(mapp[u], u, v) << endl;
            }
            else cout << -1 << endl;
        }
    }

    //timeTaken;
    return 0;
}
