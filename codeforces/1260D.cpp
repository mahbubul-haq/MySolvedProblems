#include <bits/stdc++.h>
using namespace std;
 
#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
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
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
 
//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
 
 
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
 
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }
 
///=======================================template=======================================///
 
bool comp(pair<int, pii> x, pair<int, pii> y) {
    if (x.ff == y.ff) {
        if (x.ss.ff == y.ss.ff) {
            return x.ss.ss > y.ss.ss;
        }
        return x.ss.ff < y.ss.ff;
    }
    return x.ff > y.ff;
}
 
int main() {
    //FI;//FO;
    //FastIO; //timeInit;
 
    ll m, n, k, t;
    cin >> m >> n >> k >> t;
    int ara[m];
 
    for (int i = 0; i < m; i++)
        cin >> ara[i];
 
    vector<pair<int, pii> > vec(k);
    int minid = 0;
    multiset<int> st;
 
    for (int i = 0; i < k; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        vec[i] = {d ,{l, r}};
        minid = max(minid, d);
        st.insert(d);
    }
 
    sort(all(vec), comp);
    minid++;
 
    ll l = 0, r = minid;
 
    while (l <= r) {
        int mid = (l + r) >> 1;
        vii ve;
        for (auto &u : vec) {
            if (u.ff >= mid) {
                ve.pb(u.ss);
            } else break;
        }
        int poss = 0, ri = 0, tempt = t;
        int i = 0;
        sort(all(ve));
 
        while (siz(ve) != 0) {
 
            pii now = ve[i];
            if (ri <= now.ff - 1) {
                tempt -= 3 * (ri - poss);
                tempt -= (now.ff - 1 - ri);
                poss = now.ff - 1;
                ri = now.ss;
            }
            else ri = max(ri, now.ss);
            i++;
            //bug(tempt, now.ff, now.ss, mid, minid, ri);
 
            if (i >= siz(ve)) {
 
                tempt -= 3 * (ri - poss);
                tempt -= (n + 1 - ri);
 
                break;
            }
        }
 
        if (tempt >= 0) {
            minid = min(mid, minid);
            r = mid - 1;
        } else l = mid + 1;
 
        //bug(minid, mid, tempt);
        //bug(tempt, minid);
    }
 
    int cnt = 0;
 
    auto it = st.lower_bound(minid);
    if (it != st.begin()) {
        it--;
        minid = *it;
    }
 
    for (int i = 0; i < m; i++) {
        if (ara[i] >= minid)
            cnt++;
    }
    cout << cnt << endl;
 
    //timeTaken;
    return 0;
}
