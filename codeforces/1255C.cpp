#include <bits/stdc++.h>
using namespace std;
 
#define all(v)                      v.begin(), v.end()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define sRand                       srand(chrono::steady_clock::now().time_since_epoch().count())
#define timeTaken                   endd = clock(); cout << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>
#define bug(...)                    cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
 
//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
*/
 
template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};
 
template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}
 
template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }
 
ll Set(ll N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(ll N, int pos){ return (bool) (N & (1LL << pos)); }
 
///=======================================template=======================================///
 
#define data pair<pair<int, int> ,int >
#define x ff.ff
#define y ff.ss
#define z ss
 
int main() {
    //FI;FO;
    //FastIO;//timeInit;
 
    int n;
    cin >> n;
 
    set<pii> st;
 
    int cnt[n + 1];
    mem(cnt, 0);
 
    set<data> vec[n + 1];
 
    for (int i = 0;i < n - 2; i++) {
        data d;
        cin >> d.x >> d.y >> d.z;
        vec[d.x].insert(d);
        vec[d.y].insert(d);
        vec[d.z].insert(d);
        cnt[d.x]++;
        cnt[d.y]++;
        cnt[d.z]++;
    }
 
    int str = 0;
 
    int incnt[n + 1];
    mem(incnt, 0);
    for (int i = 1; i <= n; i++) {
        st.insert({cnt[i], i});
        if (cnt[i] == 1)
            str = i;
        incnt[i] = cnt[i];
    }
 
 
 
    int cntt = 0;
    vb vis(n + 1, false);
    while (true) {
        cntt++;
        auto it = st.find({cnt[str], str});
        pii val = *it;
        if (it == st.end())
            break;
        else
        st.erase(it);
 
       cout << val.ss << " ";
        data dd;
 
        for (auto &xxx : vec[val.ss]) {
           dd = xxx;
           cnt[dd.x]--;
           cnt[dd.y]--;
           cnt[dd.z]--;
 
        }
        if (cntt == n - 2) {
            if (vis[dd.x] and dd.x != val.ss)
                cout << dd.x <<" ";
            else if (vis[dd.y] and dd.y != val.ss)
                cout << dd.y << " ";
            else cout << dd.z << " ";
 
            if (!vis[dd.x] and dd.x != val.ss)
                cout << dd.x << endl;
            else if (!vis[dd.y] and dd.y != val.ss)
                cout << dd.y << endl;
            else cout << dd.z << endl;
            break;
        }
 
        if (cnt[dd.x] != 0) {
            vec[dd.x].erase(dd);
            auto tt = st.find({cnt[dd.x] + 1, dd.x});
            if(tt != st.end())
                st.erase(tt);
            st.insert({cnt[dd.x], dd.x});
 
 
            if (cntt == n - 3) {
                if(incnt[dd.x] == 3)
                    str = dd.x;
            }
            else if (cnt[dd.x] == 1)
                str = dd.x;
        }
 
        if (cnt[dd.y] != 0) {
            vec[dd.y].erase(dd);
            auto tt = st.find({cnt[dd.y] + 1, dd.y});
            if(tt != st.end())
                st.erase(tt);
            st.insert({cnt[dd.y], dd.y});
 
 
            if (cntt == n - 3) {
                if(incnt[dd.y] == 3)
                    str = dd.y;
            }
            else if (cnt[dd.y] == 1)
                str = dd.y;
        }
 
        if (cnt[dd.z] != 0) {
            vec[dd.z].erase(dd);
            auto ttt = st.find({cnt[dd.z] + 1, dd.z});
            if(ttt != st.end())
                st.erase(ttt);
            st.insert({cnt[dd.z], dd.z});
 
 
            if (cntt == n - 3) {
                if(incnt[dd.z] == 3)
                    str = dd.z;
            }
            else if (cnt[dd.z] == 1)
                str = dd.z;
        }
 
        vis[dd.x] = vis[dd.y] = vis[dd.z] = true;
 
        if (st.empty())
            break;
    }
 
    //timeTaken;
    return 0;
}
