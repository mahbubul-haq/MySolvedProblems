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
#define fap(x)                      cout << "WTH: " << x << endl
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

vii st;
int n, k;
vi ara;
vector<pair<pii, int> > ranges;
int left(int node) {return (node << 1);}
int right(int node) { return (node << 1) | 1; }
int mid(int l, int r) {
    return (l + r) >> 1;
}

void push(int node, int l, int r) {
    if (l < r) {
        st[left(node)].ff += st[node].ss;
        st[right(node)].ff += st[node].ss;
        st[left(node)].ss += st[node].ss;
        st[right(node)].ss += st[node].ss;
        st[node].ss = 0;
    }
}

void add(int node, int l, int r, int i, int j, int val) {
    push(node, l, r);
    if (i > r or l > j)
        return ;
    if (l >= i and r <= j) {
        st[node].ff += val;
        st[node].ss += val;
        return;
    }
    int m = mid(l, r);
    add(left(node), l , m, i , j ,  val);
    add(right(node), m + 1, r, i, j, val);
}

int get(int node, int l, int r, int id) {
    push(node, l, r);
    if (id > r or id < l)
        return 0;
    int m = mid(l, r);
    if (id == l and id == r)
        return st[node].ff;
    return (get(left(node), l, m, id) + get(right(node), m + 1, r, id));
}

int main() {
    //FI;FO;
    FastIO;//timeInit;

    const int nn = 200005;
    cin >> n >> k;
    st.assign(4 * nn + 1, {0, 0});
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges.pb({{l, r}, i + 1});
    }

    sort(all(ranges));

    multiset<pair<pii, int > > mset;

    int cur = 0, pos = 1;
    while (true) {
        int l = ranges[cur].ff.ff, r = ranges[cur].ff.ss, id = ranges[cur].ss;

        if (pos == l) {
            mset.insert({{r - 1, l - 1}, id});
            add(1, 0, nn - 1, l - 1, r - 1, 1);
            int cnt = get(1, 0, nn - 1, pos - 1);
            if (cnt > k) {
                auto it = mset.end();
                it--;
                ara.pb((*it).ss);
                add(1, 0, nn - 1, (*it).ff.ss, (*it).ff.ff, -1);
                mset.erase(it);
            }
            cur++;
        }
        else {
            pos++;
        }
        if (cur >= n)
            break;
    }

    cout << siz(ara) << endl;
    for (auto v : ara) {
        cout << v << " ";
    }
    cout << endl;

    //timeTaken;
    return 0;
}
