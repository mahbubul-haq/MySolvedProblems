#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <complex>
#include <map>
#include <unordered_map>
#include <climits>
#include <bitset>
#include <queue>
#include <chrono>
#include <random>
#include <typeinfo>
#include <stack>
#include <list>
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

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

///=======================================template=======================================///

vvi st;
int n;
string str;
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)
#define mid(l, r) ((l + r) >> 1)

void build(int node, int l, int r) {
    if (l == r) {
       st[node][str[l] - 'a']++;
    }
    else {
        int md = mid(l, r);
        build(left(node), l, md);
        build(right(node), md + 1, r);
        for (int i = 0; i < 26; i++) {
            st[node][i] = st[left(node)][i] + st[right(node)][i];
        }
    }
}

vi query(int node, int l, int r, int i, int j) {
    if (l > j or r < i)
        return vi();
    else if (l >= i and r <= j)
        return st[node];
    else {
        int md = mid(l, r);

        vi s(26, 0), ri , le;
        le = query(left(node), l, md, i, j);
        ri  = query(right(node), md + 1, r, i, j);
        for (int ii = 0; ii < 26; ii++) {
            if (!le.empty()) {
                s[ii] = le[ii];
            }
            if (!ri.empty()) {
                s[ii] += ri[ii];
            }
        }

        return s;
    }
}

void update(int node, int l, int r, int pos, int c, char prev) {
    if (l > pos or r < pos)
        return;
    if (l == r) {
        st[node][prev - 'a'] = 0;
        st[node][c]++;
        return;
    }
    else {
        int md = mid(l, r);
        update(left(node), l, md, pos, c, prev);
        update(right(node), md + 1, r, pos, c, prev);
        for (int i = 0; i < 26; i++) {
            st[node][i] = st[left(node)][i] + st[right(node)][i];
        }
    }
}

int main() {
    //FI;//FO;
    FastIO; //timeInit;

    cin >> str;
    n = siz(str);
    st.resize(4 * n, vi(26, 0));

    build(1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            char prev = str[pos];
            str[pos] = c;
            update(1, 0, n - 1, pos, (c - 'a'), prev);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vi ans =  query(1, 0, n - 1, l, r);
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                if (ans[i] > 0)
                    cnt++;
            cout << cnt << endl;
        }
    }

    //timeTaken;
    return 0;
}



