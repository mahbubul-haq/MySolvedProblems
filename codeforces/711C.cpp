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

int main() {

    int n, m, k;
    cin >> n >> m >> k;
    int ara[n];
    for (auto &u : ara)
        cin >> u;

    ll p[n][m];
    for (auto &u : p) {
        for (auto &v : u) {
            cin >> v;
        }
    }

    ll dp[n][k + 5][m + 5];
    bool vis[n][k + 5][m + 5];
    mem(vis, false);
    for (auto &u : dp) {
        for (auto &v : u)
            for (auto &w : v)
                w = INF;
    }

    if (ara[0]) {
        vis[0][1][ara[0]] = true;
        dp[0][1][ara[0]] = 0;
    }
    else {
        for (int i = 1; i <= m; i++) {
            vis[0][1][i] = true;
            dp[0][1][i] = p[0][i - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        if (ara[i] != 0) {
            int col = ara[i];
            for (int cnt = 1; cnt <= k; cnt++) {
                ll equal = INF, plus = INF;
                for (int mm = 1; mm <= m; mm++) {
                    if (vis[i - 1][cnt][mm]) {
                        if (mm == col) {
                            equal = min(equal, dp[i - 1][cnt][mm]);
                        }
                        else {
                            plus = min(plus, dp[i - 1][cnt][mm]);
                        }
                    }
                }

                if (equal != INF) {
                    vis[i][cnt][col] = true;
                    dp[i][cnt][col] = min(dp[i][cnt][col], equal);
                }
                if (plus != INF and cnt < k) {
                    dp[i][cnt + 1][col] = min(dp[i][cnt + 1][col], plus);
                    vis[i][cnt + 1][col] = true;
                }
            }
        }else {
            for (int col = 1; col <= m; col++) {
                for (int cnt = 1; cnt <= k; cnt++) {
                    ll equal = INF, plus = INF;
                    for (int mm = 1; mm <= m; mm++) {
                        if (vis[i - 1][cnt][mm]) {
                            if (mm == col) {
                                equal = min(equal, dp[i - 1][cnt][mm] + p[i][col - 1]);
                            }
                            else {
                                plus = min(plus, p[i][col - 1] + dp[i - 1][cnt][mm]);
                            }
                        }
                    }

                    if (equal != INF) {
                        vis[i][cnt][col] = true;
                        dp[i][cnt][col] = min(dp[i][cnt][col], equal);
                    }
                    if (plus != INF and cnt < k) {
                        dp[i][cnt + 1][col] = min(dp[i][cnt + 1][col], plus);
                        vis[i][cnt + 1][col] = true;
                    }
                }
            }
        }
    }

    ll mini = INF;

    for (int i = 1; i <= m; i++) {
        mini = min(mini, dp[n - 1][k][i]);
    }

    if (mini == INF)
        cout << -1 << endl;
    else cout << mini << endl;

    return 0;
}
