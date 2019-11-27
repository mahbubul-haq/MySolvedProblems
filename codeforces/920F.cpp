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

vi primes;
vb isPrime;
#define maxn 1000005

void sieve() {
    isPrime.assign(maxn, true);
    primes.pb(2);
    int lim = sqrt(maxn) + 1;
    for (int i = 3;i < maxn; i += 2) {
        if (isPrime[i]) {
            primes.pb(i);
            if (i <= lim) {
                for (int j = i * i; j < maxn; j += 2 * i)
                    isPrime[j] = true;
            }
        }
    }
}

int numofDiv(int n) {
    int pfi = 0, pf = primes[pfi], ans = 1;
    while (pf * pf <= n) {
        if (n % pf == 0) {
            int cnt = 0;
            while (n % pf == 0)
                n /= pf, cnt++;
            ans *= (cnt + 1);
        }
        pf = primes[++pfi];
    }
    if (n != 1)
        ans <<= 1;
    return ans;
}

int n, m;
vi ara, d;
vector<pair<ll, bool> > st;

#define mid(l, r) ((l + r) >> 1)
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)

void build(int node, int l, int r) {
    if (l == r) {
        st[node].ff = ara[l];
        st[node].ss = (d[ara[l]] == ara[l]);
    }
    else {
        int md = mid(l, r);
        build(left(node), l, md);
        build(right(node), md + 1, r);
        st[node].ff = st[left(node)].ff + st[right(node)].ff;
        st[node].ss = st[left(node)].ss & st[right(node)].ss;
    }
}

ll sum(int node, int l, int r, int i, int j, bool rep) {
    if (i > r or j < l or l > r)
        return 0;
    if (l >= i and r <= j) {
        if (rep & !st[node].ss) {
            if (l == r) {
                st[node].ff = d[st[node].ff];
                st[node].ss = (d[st[node].ff] == st[node].ff);
                return st[node].ff;
            }
            else {
                int md = mid(l, r);
                ll val = sum(left(node), l, md, i, j, rep);
                ll val1 = sum(right(node), md + 1, r, i, j, rep);
                st[node].ff = st[left(node)].ff + st[right(node)].ff;
                st[node].ss = st[left(node)].ss & st[right(node)].ss;
                return (val + val1);
            }

        }
        else return st[node].ff;

    }
    else {
        int md = mid(l, r);
        ll val = 0;
        if (rep) {
            val = sum(left(node), l, md, i, j, rep) + sum(right(node), md + 1, r, i, j, rep);
            st[node].ff = st[left(node)].ff + st[right(node)].ff;
            st[node].ss = st[left(node)].ss & st[right(node)].ss;
            return val;
        }
        else {
            return sum(left(node), l, md, i, j, rep) + sum(right(node), md + 1, r, i, j, rep);
        }

    }
}

int main() {
    //FI;//FO;
    FastIO; //timeInit;
    sieve();

    d.resize(maxn);
    for (int i = 1; i < maxn; i++)
        d[i] = numofDiv(i);

    cin >> n >> m;
    ara.resize(n);

    for (int i = 0; i < n; i++)
        cin >> ara[i];

    st.assign(4 * n, {0, false});

    build(1, 0, n - 1);
    while (m--) {
        int t, i, j;
        cin >> t >> i >> j;
        i--, j--;
        if (t == 1) {
            sum(1, 0, n - 1, i, j, true);
        }
        else {
            cout << sum(1, 0, n - 1, i, j, false) << endl;
        }
    }

    //timeTaken;
    return 0;
}
