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

    int n, m;
    cin >> n >> m;
    string suits = "CDHS";
    char rank[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    string jokers[] = {"J1", "J2"};

    string mat[n][m];
    vector<string> option;
    umsi tak;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            tak[mat[i][j]] = 1;
        }
    }

    for (char &i : rank) {
        for (char &j : suits) {
            string now;
            now += i;
            now += j;
            if (!tak[now])
                option.pb(now);
        }
    }

    bool ok = false;
    string j1 = "void", j2 = "void";
    vii res;

    vii jok(2, {-1, -1});

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (mat[r][c] == jokers[0])
                jok[0] = {r, c};
            else if (mat[r][c] == jokers[1])
                jok[1] = {r, c};
        }
    }

    for (int i = 0; i <siz(option); i++) {
        for (int j = 0; j < siz(option); j++) {
            if (i == j  and (jok[0].ff != -1 and jok[1].ff != -1))
                continue;
            int cnt = 1;
            for (int k = 0; k < 2; k++) {
                if (jok[k].ff != -1) {
                    if (cnt) {
                        mat[jok[k].ff][jok[k].ss] = option[i];
                        cnt = 0;
                    }
                    else
                        mat[jok[k].ff][jok[k].ss] = option[j];
                }
            }
            vii ans;
            for (int r = 0; r < n - 2; r++) {
                for (int c = 0; c < m - 2; c++) {
                    set<char> ran, sui;
                    for (int cn = 0; cn < 3 ; cn++) {
                        for (int jj = 0; jj < 3; jj++) {
                            ran.insert(mat[r + cn][c + jj][0]);
                            sui.insert(mat[r + cn][c + jj][1]);
                        }
                    }
                    if (siz(sui) == 1 or siz(ran) == 9) {
                        ans.pb({r, c});
                    }
                }
            }

            for (int f = 0; f < siz(ans); f++) {
                for (int s = f + 1; s < siz(ans); s++) {
                    if (abs(ans[f].ff - ans[s].ff) > 2 or abs(ans[f].ss - ans[s].ss) > 2) {
                        res.pb(ans[f]);
                        res.pb(ans[s]);
                        ok = true;

                        cnt = 1;

                        for (int k = 0; k < 2; k++) {
                            if (jok[k].ff != -1) {
                                if (cnt) {
                                    (k == 0 ? j1 : j2) = option[i];
                                    cnt = 0;
                                }
                                else
                                    (k == 0 ? j1 : j2) = option[j];
                            }
                        }
                        goto loop;
                    }
                }
            }

        }
    }

    loop:

    if (ok) {
        cout << "Solution exists." << endl;
        if (j1 == "void" and j2 == "void") {
            cout << "There are no jokers." << endl;
        }
        else if (j1 == "void") {
            cout << "Replace J2 with " << j2 << "." << endl;
        }
        else if (j2 == "void") {
            cout << "Replace J1 with " << j1 << "." << endl;
        }
        else cout << "Replace J1 with " << j1 << " and J2 with " << j2 << "." << endl;
        cout << "Put the first square to (" << res[0].ff + 1 << ", " << res[0].ss + 1 << ")." << endl;
        cout << "Put the second square to (" << res[1].ff + 1 << ", " << res[1].ss + 1 << ")." << endl;
    }
    else {
        cout << "No solution." << endl;
    }

    return 0;
}
