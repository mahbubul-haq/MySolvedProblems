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
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos));}

///=======================================template=======================================///
int n, mm;
vvi ara;
vvi st;
int left(int node) { return (node << 1); }
int right(int node) { return ((node << 1) | 1); }
int mid(int l, int r) { return ((l + r ) >> 1); }

void combine (int node) {

    st[node][0] = min(st[left(node)][0], st[right(node)][0]);

    for(int i = 1; i < 11; i++){
        st[node][i] = min(st[left(node)][i], st[right(node)][i]);
        if(st[left(node)][i] != INT_MAX and st[right(node)][i] != INT_MAX){
            st[node][0] = min(st[node][0], st[left(node)][i] + st[right(node)][i]);
        }
    }
}

void build (int node, int l, int r) {
    if(l == r){
        for (int i = 1; i < siz(ara[l]); i++){
            st[node][ara[l][i]] = ara[l][0];
        }
        return ;
    }
    int m = mid(l, r);
    build(left(node), l, m);
    build(right(node), m + 1, r);
    combine(node);
}

void update (int node, int l, int r, int id){
    if (l > id or r < id or l > r)
        return ;
    if (l == r and r == id){
        for(int i = 0; i < 11; i++)
            st[node][i] = INT_MAX;

        for(int i = 1; i < siz(ara[id]); i++){
            st[node][ara[l][i]] = ara[l][0];
        }

        return ;
    }

    int m = mid(l, r);
    update(left(node), l, m, id);
    update(right(node), m + 1, r, id);

    combine(node);
}
vi ans;
void combine1 (int node) {
    ans[0] = min(ans[0], st[node][0]);
    for(int i = 1; i < 11; i++){
        if (ans[i] != INT_MAX and st[node][i] != INT_MAX){
            ans[0] = min(ans[0], ans[i] + st[node][i]);
        }
        ans[i] = min(ans[i], st[node][i]);
    }
}

void query (int node, int l, int r, int i, int j){
    if( l > r or r < i or l > j) {
        return ;
    }
    if( l >= i and r <= j){
        combine1(node);
        return ;
    }

    query(left(node), l, mid(l, r), i, j);
    query(right(node), mid(l, r) + 1, r, i, j);
}

int main() {
    //FI;//FO;
    FastIO;

    cin >> n >> mm;
    st.resize(4 * n, vi(11,INT_MAX) );// ans at index 0
    ara.resize(n);


    for (int i = 0; i < n; i++) {
        int now; cin >> now;
        ara[i].pb(now);
        int j = 1;
        while(now > 0){
            int n = now % 10;
            if(n > 0)
                ara[i].pb(j);
            j++;
            now /= 10;
        }
    }

    build(1, 0, n - 1);

    while(mm-- > 0){
        int type; cin >> type;
        if (type == 1){
            int id, val;
            cin >> id >> val;
            id--;
            vi tem;
            tem.pb(val);

            int j = 1;
            while(val > 0){
                int t = val % 10;
                if (t > 0)
                    tem.pb(j);
                j++;
                val /= 10;
            }
            ara[id] = tem;
            update(1, 0, n - 1, id);

        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;

            ans.assign(11, INT_MAX);
            query(1, 0, n - 1, l, r);
            if(ans[0] == INT_MAX)
                cout << -1 <<endl;
            else cout << ans[0] <<endl;
        }
    }

    //timeTaken;
    return 0;

}
