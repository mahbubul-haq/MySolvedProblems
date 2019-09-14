#include <bits/stdc++.h>
using namespace std;
 
#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-10
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
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos));}
 
///=======================================template=======================================///
vvi g;
vb tak;
int ans;
vi cnt;
 
void dfs(int u) {
    tak[u] = true;
 
    vi dod;
    int cntt = 0;
    for(auto v: g[u]) {
        if(!tak[v])
        {tak[v] =true;
        dod.pb(v);
        cntt++;
        }
    }
 
    ans+=cntt;
    for(auto v:dod)
        dfs(v);
}
 
int main() {
    //FI;//FO;
    FastIO;//timeInit;
 
    int n,k; cin >> n>>k;
    map<pii, bool >taken;
 
    vii ara;
    cnt.assign(n+1,0);
 
    g.assign(n+1,vi());
    for(int i = 0; i<k;i++) {
        int x, y;
        cin >> x>>y;
        if(x>y)
            swap(x,y);
        if(!taken[{x,y}]){
            taken[{x,y}] = true;
            ara.pb({x,y});
            cnt[x]++,cnt[y]++;
            g[x].pb(y);
            g[y].pb(x);
        }
    }
 
    vector<pair<int, pii > > vec;
 
    for(int i=0;i<siz(ara);i++) {
        vec.pb({cnt[ara[i].ff]+cnt[ara[i].ss]-1,{ara[i].ff,ara[i].ss}});
    }
 
    sortv(vec);
 
    tak.assign(n + 1,false);
    ans = 0;
    for(int i= 0;i<siz(vec);i++) {
        if(tak[vec[i].ss.ff] and tak[vec[i].ss.ss])
            continue;
 
        if(!tak[vec[i].ss.ff]){
            tak[vec[i].ss.ff] = true;
 
            int cntt = 0;
 
            for(auto v:g[vec[i].ss.ff]){
                if(!tak[v])
                    cntt++;
            }
            if(cntt==0)
                cntt++;
            ans+=cntt;
            vi dod;
            for(auto v:g[vec[i].ss.ff]) {
                if (!tak[v]) {
                    dod.pb(v);
                    tak[v] = true;
                }
            }
            for(auto v:dod)
                dfs(v);
 
        }
 
        if(!tak[vec[i].ss.ss]){
            tak[vec[i].ss.ss] = true;
 
            int cntt = 0;
 
            for(auto v:g[vec[i].ss.ss]){
                if(!tak[v])
                    cntt++;
            }
            if(cntt==0)
                cntt++;
            ans+=cntt;
            vi dod;
            for(auto v:g[vec[i].ss.ss]) {
                if (!tak[v]) {
                    dod.pb(v);
                    tak[v] = true;
                }
            }
            for(auto v:dod)
                dfs(v);
 
        }
 
        tak[vec[i].ss.ff] =true;
        tak[vec[i].ss.ss] = true;
    }
 
    cout << k - ans <<endl;
 
    //timeTaken;
    return 0;
}
